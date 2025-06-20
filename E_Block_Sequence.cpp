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
    int N; cin >> N;
    vector<int> arr(N);
    fillv(arr, N);

    vector<ll> opsReq(N+1, 0);
    vector<ll> dp(N+1, 0);
    //dp[i] = ans for suffix i if we take i

    for(int i = N-1; i >= 0; i--)
    {
        //is i valid to take??
        if(i + arr[i] < N)
        {
            dp[i] = opsReq[arr[i] + i + 1];
        }
        else 
        {
            dp[i] = 1e9;
        }

        //if we don't take it, then we need to add one operation
        opsReq[i] = min(opsReq[i+1] + 1, dp[i]);
    }

    ll ans = 1e9;
    for(int i = 0; i <= N; i++)
    {
        ans = min(ans, dp[i] + i);
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
