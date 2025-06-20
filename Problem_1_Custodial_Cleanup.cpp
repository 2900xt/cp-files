#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

template <typename T>
inline void fillv(vector<T>& v, int n) {
    for (int i = 0; i < n; ++i) {
        std::cin >> v[i];
    }
}

inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solveSubtask1(int N, int M)
{
    vector<int> reqCol(N), startingCol(N), endingCol(N);
    fillv(reqCol, N);
    fillv(startingCol, N);
    fillv(endingCol, N);

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //do bfs for dp
    typedef pair<int, vector<int>> state;
    //(cur node, colors of cells)
    set<state> vis{};
    queue<state> bfsQ{};
    bfsQ.push({0, startingCol});

    while(!bfsQ.empty())
    {
        auto cur = bfsQ.front();
        bfsQ.pop();

        if(vis.count(cur)) continue;
        vis.insert(cur);

        auto [curNode, cellColors] = cur;
        dbg(curNode) dbg(cellColors)

        multiset<int> hasColors{};
        for(int i = 0; i < N; i++)
        {
            hasColors.insert(startingCol[i]);
        }

        for(int i = 0; i < N; i++)
        {
            if(hasColors.count(cellColors[i]))
            {
                hasColors.erase(hasColors.find(cellColors[i]));
            }
        }

        //pick color from this cell if not picked already
        if(cellColors[curNode] == startingCol[curNode])
        {
            cellColors[curNode] = -1;
            bfsQ.push({curNode, vector<int>(cellColors)});
            cellColors[curNode] = startingCol[curNode];
        }

        //place end color if we have it and cell empty
        if(hasColors.count(endingCol[curNode]) && cellColors[curNode] == -1)
        {
            cellColors[curNode] = endingCol[curNode];
            bfsQ.push({curNode, vector<int>(cellColors)});
            cellColors[curNode] = -1;
        }

        //enter stall if connected to it and has req color
        for(int n : adj[curNode])
        {
            if(hasColors.count(reqCol[n]) || n == 0)
            {
                bfsQ.push({n, vector<int>(cellColors)});
            }
        }
    }

    if(vis.count({0, endingCol}))
    {
        cout << "YES" << endll;
    }
    else 
    {
        cout << "NO" << endll;
    }
}

void SolveSubtask2(int N, int M)
{
    vector<int> reqCol(N), startingCol(N), endingCol(N);
    fillv(reqCol, N);
    fillv(startingCol, N);
    fillv(endingCol, N);

    vector<vector<int>> adj(N);
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    map<int, vector<int>> nodesByColor{};
    for(int i = 0; i < N; i++)
    {
        nodesByColor[reqCol[i]].push_back(i);
    }

    //if we encounter the color of a node, we can now visit it.
    vector<bool> vis(N), unlock(N);
    queue<int> q{};
    set<int> cols{};
    q.push(0);

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        if(vis[cur]) continue;
        vis[cur] = true;
        unlock[cur] = true;

        for(int m : adj[cur])
        {
            unlock[m] = true;
            if(cols.count(reqCol[m]))
            {
                q.push(m);
            }
        }

        cols.insert(startingCol[cur]);
        for(int n : nodesByColor[startingCol[cur]])
        {
            if(unlock[n])
            {
                q.push(n);
            }
        }
        
    }

    for(int i = 0; i < N; i++)
    {
        if(!vis[i])
        {
            cout << "NO" << endll;
            return;
        }
    }

    cout << "YES" << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1; cin >> T;
    for(ll t = 0; t < T; t++)
    {
        int N, M; cin >> N >> M;
        if(N <= 8) solveSubtask1(N, M);
        else SolveSubtask2(N, M);
    }
}
