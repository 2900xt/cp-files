#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif


struct DSU {
    vector<ll> e;
    DSU(ll N) {
        e = vector<ll>(N, -1); 
    }
    void init(ll N) { 
        e = vector<ll>(N, -1); 
    }
    ll get(ll x) { 
        return e[x] < 0 ? x : e[x] = get(e[x]); 
    }
        bool sameSet(ll a, ll b) {
        return get(a) == get(b); 
    }
    ll size(ll x) {
        return -e[get(x)]; 
    }
    bool unite(ll x, ll y) { // union by size
        x = get(x), y = get(y);
        if (x == y)
            return 0;
        if (e[x] > e[y])
            swap(x, y);
        
        e[x] += e[y];
        e[y] = x;
        return 1;
    }
};

ll nC2(ll n)
{
    return (n*(n-1))/2;
}

void solveAll0(int N, int M, string s)
{
    vector<set<int>> adj(N);
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    vector<ll> ans(N+1, 0);
    DSU dsu(N);

    for(int i = N-1; i >= 0; i--)
    {
        ans[i] = ans[i+1];
        if(s[i] == '0')
        {
            //add node i to graph
            for(auto it : adj[i])
            {
                if(s[it] == '0' && !dsu.sameSet(i, it) && it > i)
                {
                    int cc1 = dsu.size(i);
                    int cc2 = dsu.size(it);
                    dsu.unite(i, it);

                    int cc3 = dsu.size(i);
                    ans[i] += nC2(cc3) - nC2(cc1) - nC2(cc2);
                }
            }
        }
    }

    for(int j = 0; j < N; j++)
    {
        cout << ans[j] << endll;
    }
}

void solveAll1(int N, int M, string s)
{
    DSU dsu(N);
    map<ll, ll> compsSizes{};
    ll ans = 0;

    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        dsu.unite(u, v);
    }

    for(int i = 0; i < N; i++)
    {
        if(!compsSizes.count(dsu.get(i)))
        {
            compsSizes[dsu.get(i)] = dsu.size(i);
            ans += nC2(dsu.size(i));
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << ans << endll;

        compsSizes[dsu.get(i)]--;
        ans -= compsSizes[dsu.get(i)];
    }
}

void solveBrute(int N, int M, string s)
{
    set<pair<int, int>> edges;
    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        edges.insert({u, v});
    }

    for(int i = 0; i < N; i++)
    {
        DSU dsu(N);
        set<int> comps{};
        ll ans = 0;

        for(auto e : edges)
        {
            dsu.unite(e.first, e.second);
        }

        for(int i = 0; i < N; i++)
        {
            if(!comps.count(dsu.get(i)))
            {
                comps.insert(dsu.get(i));
                ans += nC2(dsu.size(i));
            }
        }

        cout << ans << endll;

        set<pair<int, int>> toRemove{};
        vector<int> toAdd{};
        for(auto e : edges)
        {
            if(e.first == i && e.second == i)
                continue;

            if(e.first == i)
            {
                toRemove.insert(e);
                toAdd.push_back(e.second);
            }
            else if(e.second == i)
            {
                toRemove.insert(e);
                toAdd.push_back(e.first);
            }
        }

        for(auto e : toRemove)
        {
            edges.erase(e);
        }

        if(s[i] == '1')
        {
            for(int i = 0; i < toAdd.size(); i++)
            {
                for(int j = i+1; j < toAdd.size(); j++)
                {
                    edges.insert({toAdd[i], toAdd[j]});
                }
            }
        }
    }
}

int32_t main()
{
    int N, M;
    cin >> N >> M;
    string s; cin >> s;

    if(count(all(s), '0') == N)
    {
        solveAll0(N, M, s);
        return 0;
    }

    if(count(all(s), '1') == N)
    {
        solveAll1(N, M, s);
        return 0;
    }

    if(N <= 105) solveBrute(N, M, s);
    else solveAll1(N, M, s);
}
