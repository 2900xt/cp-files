#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// I love having gay sex lol
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9 + 7)
#define inf ll(1e9 + 1)
#define INF ll(1e18 + 1)

template <typename T>
inline void fillv(vector<T> &v, ll n)
{
    for (ll i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
}

inline void open(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

vector<ll> weight;
vector<vector<ll>> adj;
vector<ll> max_alt_sum, min_alt_sum;
vector<bool> vis;
vector<ll> parent;

void dfs(ll node, ll par = -1)
{
    parent[node] = par;
    for (ll child : adj[node])
    {
        if (child == par)
            continue;
        dfs(child, node);
    }
}

void dfs2(ll node)
{
    vis[node] = true;
    ll next = parent[node];
    if (next == -1)
        return;

    if (!vis[next])
    {
        dfs2(next);
    }

    max_alt_sum[node] = max(max_alt_sum[node], -min_alt_sum[next] + weight[node]);
    min_alt_sum[node] = min(min_alt_sum[node], -max_alt_sum[next] + weight[node]);
}

void solve(ll num_tc)
{
    ll n;
    cin >> n;
    weight = vector<ll>(n);
    adj = vector<vector<ll>>(n);
    max_alt_sum = vector<ll>(n, 0);
    min_alt_sum = vector<ll>(n, 0);
    vis = vector<bool>(n, false);
    parent = vector<ll>(n, -1);

    for (ll i = 0; i < n; i++)
    {
        cin >> weight[i];
        max_alt_sum[i] = weight[i];
        min_alt_sum[i] = weight[i];
    }

    for (ll i = 0; i < n - 1; i++)
    {
        ll u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);

    for (ll i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs2(i);
        }
    }

    for (ll i = 0; i < n; i++)
    {
        cout << max_alt_sum[i] << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++)
    {
        solve(t + 1);
    }
}
