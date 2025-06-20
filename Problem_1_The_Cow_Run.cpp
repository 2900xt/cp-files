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
    int n; cin >> n;
    vector<ll> P(n);
    fillv(P, n);
    sort(all(P));

    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, 1e18)));
    for(int i = 0; i < n; i++)
    {
        //base case: moving to position p_i takes n*p_i time
        dp[i][i][0] = n*abs(P[i]);
        dp[i][i][1] = n*abs(P[i]);
    }

    //process subarrays in order of increasing length
    //dp[i][j] depends on dp[i+1][j], dp[i][j-1].
    //dp[i][j][k] ans for segment (i, j) with ending at j <=> k = 1 
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i+1; j < n; j++)
        {
            //the remainder of the cows also suffer the damage
            int rem = n - (j - i);
            if(i < n)
            {
                //we can get the answer for this range by getting the answer for the smaller range (i+1, j)
                dp[i][j][0] = min(dp[i][j][0], min(
                    //case 1: we move from the i-end to the new i-end
                    dp[i+1][j][0] + abs(P[i+1] - P[i]) * rem,
                    //case 2: we move from the j-end to the new i-end
                    dp[i+1][j][1] + abs(P[j] - P[i]) * rem
                ));
            }
            if(j > 0)
            {
                //we can get the answer for this range by querying the answer for the range (i, j-1)
                dp[i][j][1] = min(dp[i][j][1], min(
                    //case 1: we move from old j-end to new j-end
                    dp[i][j-1][1] + abs(P[j-1] - P[j]) * rem,
                    //case 2: we move from old j-end to new i-end
                    dp[i][j-1][0] + abs(P[j] - P[i]) * rem
                ));
            }
        }
    }

    cout << min(dp[0][n-1][0], dp[0][n-1][1]) << endll;
}

int32_t main()
{
    open("cowrun");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
