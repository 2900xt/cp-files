#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// I love having gay sex lol
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;
typedef long double ld;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

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
    int w, b; cin >> w >> b;
    // Suppose w, b are given.
    // We create dp arrays sized [w+1][b+1][2], where index [i][j][0] = P[i][j], [i][j][1] = D[i][j].
    ld dp[w+1][b+1][2];
    for(int i = 0; i <= w; i++) for(int j = 0; j <= b; j++) for(int k = 0; k < 2; k++) dp[i][j][k] = 0;

    // Base cases:
    dp[0][0][0] = 0.0L;
    dp[0][0][1] = 0.0L;

    // Only white mice:
    for(int i = 1; i <= w; i++){
        dp[i][0][0] = 1.0L;  // princess turn with only whites: she draws white and wins.
        dp[i][0][1] = 0.0L;  // dragon turn with only whites: dragon draws white and wins => princess loses.
    }
    // Only black mice:
    for(int j = 1; j <= b; j++){
        dp[0][j][0] = 0.0L;  // princess turn with only blacks: no white ever => princess loses.
        dp[0][j][1] = 0.0L;  // dragon turn with only blacks: no white ever => princess loses.
    }

    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= b; j++){
            ld total = (ld)(i + j);
            // Princess turn P[i][j]:
            // If princess draws white: i/(i+j) * 1.
            // If princess draws black: j/(i+j) * D[i][j-1].
            dp[i][j][0] = (ld)i/total;
            dp[i][j][0] += (ld)j/total * dp[i][j-1][1];

            // Dragon turn D[i][j]:
            // If dragon draws white: i/(i+j) * 0 (princess loses).
            // If dragon draws black: j/(i+j) * { panic jump branch }.
            ld dragonProb = 0.0L;
            ld afterDrawTotal = (ld)(i + (j-1));
            // Only if afterDrawTotal > 0; but since i>=1 or j-1>=1 for (i>=1,j>=1), afterDrawTotal >= 1.
            ld branchSum = 0.0L;
            // Panic jump removes white:
            branchSum += (ld)i/afterDrawTotal * dp[i-1][j-1][0];  // go to P[i-1][j-1]
            // Panic jump removes black:
            if(j-1 >= 1){
                branchSum += (ld)(j-1)/afterDrawTotal * dp[i][j-2][0]; // go to P[i][j-2]
            }
            dragonProb = (ld)j/total * branchSum;
            
            dp[i][j][1] = dragonProb;
        }
    }

    cout << fixed << setprecision(9) << dp[w][b][0] << endll;

}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    //dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
