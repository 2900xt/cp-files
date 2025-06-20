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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

vector<vector<int>> adj{}, comps{};
vector<int> vis{};
void dfs(int node, int comp)
{
    vis[node] = 1;
    comps[comp].push_back(node);

    for (auto& child : adj[node]) {
        if (!vis[child]) {
            dfs(child, comp);
        }
    }
}

void solve(int num_tc)
{
    int N, K; cin >> N >> K;
    adj = vector<vector<int>>(N);
    vis = vector<int>(N);
    comps.clear();

    string s; cin >> s;
    string t; cin >> t;

    auto addEdge = [&](int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    for(int i = 0; i < N; i++)
    {
        if(i+K < N)
        {
            addEdge(i+K, i);
        }

        if(i-K >= 0)
        {
            addEdge(i-K, i);
        }

        if(i+K+1 < N)
        {
            addEdge(i+K+1, i);
        }

        if(i-K-1 >= 0)
        {
            addEdge(i-K-1, i);
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(!vis[i])
        {
            comps.push_back({});
            dfs(i, comps.size()-1);
        }
    }

    for(int i = 0; i < comps.size(); i++)
    {
        string s1 = "", s2 = "";
        for(auto& j : comps[i])
        {
            s1 += s[j];
            s2 += t[j];
        }

        sort(all(s1));
        sort(all(s2));
        if(s1 != s2)
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

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
