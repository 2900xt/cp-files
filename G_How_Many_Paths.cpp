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
set<pair<int, int>> used{};
vector<int> ans{}, flag{};

void dfs(int node)
{
    for(auto& child : adj[node])
    {
        if(ans[child] < 2) 
        {
            ans[child] += ans[node];
            dfs(child);
        }
    }
}

void solve(int num_tc)
{
    int N, M; cin >> N >> M;

    ans = vector<int>(N, 0);
    flag = vector<int>(N, 0);
    adj = vector<vector<int>>(N);
    used = set<pair<int, int>>();

    vector<int> indeg(N, 0);

    for(int i = 0; i < M; i++)
    {
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        indeg[v]++;
    }

    ans[0] = 1;

    dfs(0);

    queue<int> khanQ{};
    for(int i = 0; i < N; i++)
    {
        if(indeg[i] == 0)
        {
            khanQ.push(i);
        }
    }

    while(!khanQ.empty())
    {
        int cur = khanQ.front();
        khanQ.pop();
        flag[cur] = 1;

        for(auto& child : adj[cur])
        {
            indeg[child]--;
            if(indeg[child] == 0)
            {
                khanQ.push(child);
            }
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(flag[i]) cout << min(2, ans[i]) << " ";
        else cout << -1 << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
