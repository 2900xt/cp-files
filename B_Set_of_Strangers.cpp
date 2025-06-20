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
    int N, M; cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M));
    vector<int> found(N*M+69, 0);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    set<int> cols{};

    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cols.insert(grid[i][j]);
            for(int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if(x >= 0 && x < N && y >= 0 && y < M)
                {
                    if(grid[i][j] == grid[x][y])
                    {
                        found[grid[i][j]] = 1;
                    }
                }
            }
        }
    }

    int ans = 0;
    int mx = 0;
    for(int c : cols)
    {
        if(found[c] == 0)
        {
            ans++;
            mx = max(mx, 1);
        }
        else
        {
            ans += 2;
            mx = max(mx, 2);
        }
    }
    cout << ans - mx << endll;
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
