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

#define MOD ll(998244353)
#define inf int(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

long long binExp(long long a, long long b) {
    if (b == 0)
      return 1;
  
    long long res = binExp(a, b / 2) % MOD;
    if (b & 1) {
      return (a * ((res * res) % MOD)) % MOD;
    } else
      return (res * res) % MOD;
  }

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
    ll N; cin >> N;
    vector<ll> a(N);
    fillv(a, N);

    ll ans = 0, cur = 0, num = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i] == 1)
        {
            cur = (cur + 1) % MOD;
            num = (num + 1) % MOD;
        }
        if(a[i] == 2)
        {
            cur *= 2;
            cur %= MOD;
        }
        if(a[i] == 3)
        {
            ans += (cur - num + MOD) % MOD;
            ans %= MOD;
        }
    }
    cout << ans % MOD << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
