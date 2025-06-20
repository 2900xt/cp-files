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

vector<string> grid;
int N, M;
ll numWaysToPlace(int numTowersLeft, int curRow, int curCol)
{
    if(numTowersLeft == 0) return 1;

    cerr << curRow << ", " << curCol << endll;

    ll ans = 0;
    for(int i = 0; i < N; i++)
    {
        //place next tower at i, curCol
        if(grid[i][curCol] == '#' || i == curRow) continue;
        ans += numWaysToPlace(numTowersLeft - 1, i, curCol);
    }

    for(int i = 0; i < M; i++)
    {
        //place next tower at curRow, i
        if(grid[curRow][i] == '#' || i == curCol) continue;
        ans += numWaysToPlace(numTowersLeft - 1, curRow, i);
    }

    return ans;
}

void solve(int num_tc)
{ 
    cin >> N >> M;
    grid = vector<string>(N);
    fillv(grid, N);

    ll ans = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(grid[i][j] == '#') continue;
            cerr << "S: " << i << ", " << j << endll;
            ans += numWaysToPlace(1, i, j);
        }
    }

    cout << ans << endll;
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
