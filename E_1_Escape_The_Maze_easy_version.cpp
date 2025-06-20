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

void solve(int num_tc)
{
    int N, K; cin >> N >> K;
    vector<int> friends(K);
    for(int i = 0; i < K; i++){
        cin >> friends[i];
        friends[i]--;
    }

    vector<vector<int>> adj(N);
    for(int i = 0; i < N-1; i++){
        int u, v; cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> distFriends(N, -1);
    queue<int> q;
    for(int i = 0; i < K; i++){
        distFriends[friends[i]] = 0;
        q.push(friends[i]);
    }

    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int next = adj[curr][i];
            if(distFriends[next] == -1)
            {
                distFriends[next] = distFriends[curr] + 1;
                q.push(next);
            }
        }
    }

    vector<int> dist(N, -1);
    dist[0] = 0;
    q.push(0);
    while(!q.empty())
    {
        int curr = q.front(); q.pop();
        for(int i = 0; i < adj[curr].size(); i++)
        {
            int next = adj[curr][i];
            if(dist[next] == -1)
            {
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    for(int i = 1; i < N; i++)
    {
        if(adj[i].size() == 1 && dist[i] < distFriends[i])
        {
            cout << "YES" << endll;
            return;
        }
    }

    cout << "NO" << endll;
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
