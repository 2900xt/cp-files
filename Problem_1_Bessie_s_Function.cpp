#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
 
// Global variables.
int N;
vector<int> a, c;  // 1-indexed arrays: a[i] (function value) and c[i] (cost).
 
// For cycle detection.
vector<int> state; // 0 = unvisited, 1 = visiting, 2 = finished
vector<bool> inCycle; // true if vertex is in a cycle
vector<int> cycleId;  // if inCycle, stores which cycle (id) this vertex belongs to
vector<vector<int>> cycles; // each cycle is stored as a vector of vertices (order arbitrary for now)
 
// For tree DP (the "branches" feeding into the cycle)
vector<vector<int>> children;  // tree children (reverse edges from non-cycle vertices)
 
// DP arrays for non-cycle (tree) vertices.
vector<ll> Fdp, Gdp;
// The recurrences used here are as follows for a non-cycle vertex u:
//   Fdp[u] = min( sum_{child in tree(u)} Gdp(child),   c[u] + sum_{child in tree(u)} Fdp(child) )
//   Gdp[u] = c[u] + min( sum_{child in tree(u)} Gdp(child), sum_{child in tree(u)} Fdp(child) )
// Intuition: Fdp[u] is the cost when u does NOT “fix itself” (so it will use its parent's fixed value) 
// and Gdp[u] is the cost when u is forced to be fixed (i.e. f(u)=u).
 
// ----------------------------
// Cycle detection function.
 
void findCycles(){
    state.assign(N+1, 0);
    inCycle.assign(N+1, false);
    cycleId.assign(N+1, -1);
    int cycleCount = 0;
    for (int i = 1; i <= N; i++){
        if(state[i] != 0) continue;
        int cur = i;
        vector<int> seq;
        while (true){
            state[cur] = 1;
            seq.push_back(cur);
            int nxt = a[cur];
            if(state[nxt] == 0){
                cur = nxt;
                continue;
            } else if(state[nxt] == 1){
                // found a cycle; record vertices from the first occurrence of nxt to end.
                int pos = 0;
                while(seq[pos] != nxt) pos++;
                vector<int> cyc;
                for (int j = pos; j < seq.size(); j++){
                    cyc.push_back(seq[j]);
                    inCycle[seq[j]] = true;
                    cycleId[seq[j]] = cycleCount;
                }
                cycles.push_back(cyc);
                cycleCount++;
                break;
            } else { // state[nxt]==2, no new cycle here.
                break;
            }
        }
        // mark all vertices in seq as finished.
        for (int v : seq) {
            state[v] = 2;
        }
    }
}
 
// ----------------------------
// Build the tree structure (reverse edges from non-cycle vertices).
// Every vertex i (which is not in a cycle) points to a[i]; so add i as a child of a[i].
 
void buildTree(){
    children.assign(N+1, vector<int>());
    for (int i = 1; i <= N; i++){
        if(!inCycle[i]){
            children[a[i]].push_back(i);
        }
    }
}
 
// ----------------------------
// DFS for tree DP. (Only for non-cycle vertices.)
 
void dfsTreeDP(int u){
    ll sumF = 0, sumG = 0;
    for (int v : children[u]){
        dfsTreeDP(v);
        sumF += Fdp[v];
        sumG += Gdp[v];
    }
    Fdp[u] = min(sumG, (ll) c[u] + sumF);
    Gdp[u] = c[u] + min(sumG, sumF);
}
 
// ----------------------------
// Main
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin >> N;
    a.resize(N+1);
    c.resize(N+1);
    for (int i = 1; i <= N; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++){
        cin >> c[i];
    }
 
    // 1. Find cycles in the functional graph.
    findCycles();
 
    // 2. Build the tree structure for non-cycle vertices.
    buildTree();
 
    // 3. Compute tree DP for non-cycle vertices.
    Fdp.assign(N+1, 0);
    Gdp.assign(N+1, 0);
    // Every non-cycle vertex is reached as a child of some vertex (possibly a cycle vertex).
    for (int i = 1; i <= N; i++){
        if(!inCycle[i] && Fdp[i] == 0 && Gdp[i] == 0){
            dfsTreeDP(i);
        }
    }
 
    // For every cycle vertex, accumulate the cost from its attached tree.
    // Define T0(v) = sum_{child in tree(v)} Gdp(child) and T1(v) = sum_{child in tree(v)} Fdp(child)
    vector<ll> T0(N+1, 0), T1(N+1, 0);
    for (int v = 1; v <= N; v++){
        if(inCycle[v]){
            ll sF = 0, sG = 0;
            for (int child : children[v]){
                sF += Fdp[child];
                sG += Gdp[child];
            }
            T0[v] = sG;
            T1[v] = sF;
        }
    }
 
    // 4. Process each cycle. For each cycle, we will “fix” the function on that component by choosing for each cycle vertex
    // whether to "fix" it (i.e. set f(v)=v) or not (in which case we plan to set f(v) equal to its successor in the cycle).
    // For a cycle vertex v:
    //   - If we fix it, the cost is: A(v) = ( (a[v]==v) ? 0 : c[v] ) + T1(v)
    //   - If we do not fix it then we intend to have f(v)= next in the cycle.
    //     In that case, the cost is: C(v) = ( (a[v]== next) ? 0 : c[v] ) + T0(v)
    //
    // Moreover, the idempotence condition forces that if a vertex is not fixed then its successor in the cycle MUST be fixed.
    // We now do a DP over the cycle (which is circular) with the constraint:
    //    if s[i] == 0 then s[(i+1) mod k] must equal 1.
 
    ll ans = 0;
    // Process each cycle (each cycle appears in the "cycles" vector)
    for (auto &cyc : cycles){
        // It is more convenient to “rotate” the cycle so that the vertices appear in the natural order of the function.
        // Starting from an arbitrary vertex v, follow u = a[u] until we return.
        vector<int> order;
        int start = cyc[0];
        int cur = start;
        do {
            order.push_back(cur);
            cur = a[cur];
        } while(cur != start);
 
        int k = order.size();
        // For each vertex in the cycle (in the determined order), define:
        //   A[i] = cost if we fix order[i] (set f(order[i]) = order[i])
        //   C[i] = cost if we do NOT fix order[i] (we plan to set f(order[i]) = order[(i+1)%k])
        vector<ll> Aarr(k), Carr(k);
        for (int i = 0; i < k; i++){
            int v = order[i];
            Aarr[i] = ((a[v] == v) ? 0LL : c[v]) + T1[v];
            int nxt = order[(i+1)%k];
            Carr[i] = ((a[v] == nxt) ? 0LL : c[v]) + T0[v];
        }
 
        // Solve the following: choose s[i] in {0,1} for i = 0..k-1,
        // where 1 means "fix" (use cost Aarr) and 0 means "not fixed" (use cost Carr),
        // subject to the constraint: if s[i] == 0 then s[(i+1)%k] must equal 1.
        // We solve this by “breaking” the cycle into a linear chain and trying both possibilities for s[0].
        const ll INF = 1e18;
        ll bestCycle = INF;
 
        for (int init = 0; init < 2; init++){
            // dp[i][state]: minimal cost for vertices 0..i with vertex i assigned state 'state'
            vector<vector<ll>> dp(k, vector<ll>(2, INF));
            dp[0][init] = (init == 1 ? Aarr[0] : Carr[0]);
            for (int i = 1; i < k; i++){
                // If we set vertex i to fixed (state 1), we can come from either previous state.
                dp[i][1] = min(dp[i-1][0], dp[i-1][1]) + Aarr[i];
                // If we set vertex i to not fixed (state 0), then the previous vertex MUST have been fixed.
                dp[i][0] = dp[i-1][1] + Carr[i];
            }
            // Now enforce the cycle constraint between vertex k-1 and vertex 0:
            // If vertex k-1 is not fixed then its successor (which is vertex 0) must be fixed.
            if(init == 0){
                bestCycle = min(bestCycle, dp[k-1][1]);
            } else {
                bestCycle = min(bestCycle, min(dp[k-1][0], dp[k-1][1]));
            }
        }
 
        ans += bestCycle;
    }
 
    cout << ans << "\n";
    return 0;
}
