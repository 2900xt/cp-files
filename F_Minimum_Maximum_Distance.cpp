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

vector<vector<int>> adj{};
vector<int> special{};

int fd = -1, fid = -1;

void dfsDiameter(int node, int depth, int par = -1)
{
    if(fd < depth && special[node])
    {
        fd = depth;
        fid = node;
    }

    for(int i : adj[node])
    {
        if(i != par)
        {
            dfsDiameter(i, depth+1, node);
        }
    }
}

void getDepths(int node, int depth, vector<int> &dist, int par = -1)
{
    dist[node] = depth;

    for(int i : adj[node])
    {
        if(i != par)
        {
            getDepths(i, depth+1, dist, node);
        }
    }
}

void solve(int num_tc)
{
    int N, K; cin >> N >> K;
    adj = vector<vector<int>>(N);
    special = vector<int>(N);

    int og;
    for(int i = 0; i < K; i++)
    {
        int u; cin >> u;
        u--;
        special[u] = true;
        og = u;
    }

    for(int i = 0; i < N-1; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    fd = -1, fid = -1;
    dfsDiameter(og, 0);

    int node1 = fid;
    fd = -1, fid = -1;
    dfsDiameter(node1, 0);

    int node2 = fid;

    vector<int> depth1(N, 0), depth2(N, 0);
    getDepths(node1, 0, depth1);
    getDepths(node2, 0, depth2);

    int ans = 1e9;
    for(int i = 0; i < N; i++)
    {
        ans = min(ans, max(depth1[i], depth2[i]));
    }

    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1; cin >> T;
    
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
