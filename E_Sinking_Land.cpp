#include <queue>
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
    int H, W, Y; cin >> H >> W >> Y;
    vector<vector<ll>> grid(H, vector<ll>(W));
    vector<vector<ll>> dist(H, vector<ll>(W, 1e17));

    for(int i = 0; i < H; i++)
    {
        fillv(grid[i], W);
    }

    priority_queue<array<ll, 3>> pq;
    for(int i = 0; i < H; i++)
    {
        pq.push({-grid[i][W-1], i, W-1});
        pq.push({-grid[i][0], i, 0});
    }

    for(int i = 0; i < W; i++)
    {
        pq.push({-grid[0][i], 0, i});
        pq.push({-grid[H-1][i], H-1, i});
    }

    while(!pq.empty())
    {
        auto [d, x, y] = pq.top();
        pq.pop();
        d *= -1;
        if(d > dist[x][y]) continue;
        dist[x][y] = d;

        int xDirs[] = {1, -1, 0, 0};
        int yDirs[] = {0, 0, -1, 1};
        for(int i = 0; i < 4; i++)
        {
            int nx = x + xDirs[i], ny = y + yDirs[i];
            if(nx >= H || ny >= W || nx < 0 || ny < 0) continue;
            //cerr << "->" << nx << ", " << ny << endll;

            ll newDist = max(dist[x][y], grid[nx][ny]);
            if(newDist < dist[nx][ny])
            {
                dist[nx][ny] = newDist;
                pq.push({-newDist, nx, ny});
            }
        }
    }

    dbg(dist)

    ll cur = H*W;
    map<ll, ll> ctr{};
    for(int i = 0; i < H; i++) 
    {
        for(int j = 0; j < W; j++)
        {
            ctr[dist[i][j]]++;
        }
    }

    for(int y = 1; y <= Y; y++)
    {
        cur -= ctr[y];
        cout << cur << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
