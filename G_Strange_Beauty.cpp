#include <algorithm>
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
    vector<int> a(N);
    fillv(a, N);
    sort(all(a));

    vector<ll> dp(N);
    //length of largest subsequence ending at i
    //prev element must be a factor of current element

    vector<ll> lastOcc(2e5+69, -1);

    for(int i = 0; i < N; i++)
    {
        dp[i] = 1;
     
        for(int j = 1; j * j <= a[i]; j++)
        {
            if(a[i] % j == 0)
            {
                ll v1 = j, v2 = a[i]/j; 
                if(lastOcc[v1] != -1)
                    dp[i] = max(dp[i], dp[lastOcc[v1]] + 1);

                if(lastOcc[v2] != -1)
                    dp[i] = max(dp[i], dp[lastOcc[v2]] + 1);
            }
        }

        lastOcc[a[i]] = i;
    }

    cout << N - *max_element(all(dp)) << endll;
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
