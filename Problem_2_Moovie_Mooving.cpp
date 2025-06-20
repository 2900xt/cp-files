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
    int N, L; cin >> N >> L;
    vector<set<int>> showtimes(N);
    vector<int> durations(N);
    for(int i = 0; i < N; i++)
    {
        int D; cin >> D;
        durations[i] = D;
        int k; cin >> k;
        for(int j = 0; j < k; j++)
        {
            int x; cin >> x;
            showtimes[i].insert(x);
        }
    }

    //dp[mask] = maximum duration you can go to by watching mask movies
    vector<int> dp(1 << N, -1);
    dp[0] = 0;
    int ans = 1e9;
    for(int mask = 0; mask < (1 << N); mask++)
    {
        if(dp[mask] == -1) continue;

        if(dp[mask] >= L)
        {
            ans = min(ans, __builtin_popcount(mask));
        }

        for(int j = 0; j < N; j++)
        {
            if(mask & (1 << j)) continue;
            
            auto lb = showtimes[j].upper_bound(dp[mask]);
            if(lb == showtimes[j].begin()) continue;

            lb--;

            dp[mask | (1 << j)] = max(dp[mask | (1 << j)], *lb + durations[j]);
        }
    }

    if(ans == 1e9)
    {
        cout << -1 << endll;
        return;
    }

    cout << ans << endll;
}

int32_t main()
{
    open("movie");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
