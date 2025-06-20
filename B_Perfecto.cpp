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

ll isqrt(ll n)
{
    ll low = 0, high = n;
    while(low < high)
    {
        ll mid = low + (high - low + 1) / 2;
        ll mid2 = mid * mid;
        if(mid2 == n){
            return mid;
        }
        if(mid * mid <= n){
            low = mid;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

bool is_perfect_square(ll n)
{
    return (round(sqrt(n)) * round(sqrt(n)) == n);
}

void solve(int num_tc)
{
    ll N; cin >> N;
    vector<ll> ans(N);

    ll sum = 0;
    for(ll i = 1; i <= N; i++)
    {
        sum += i;
        if(is_perfect_square(sum))
        {
            if(i == N)
            {
                cout << -1 << endll;
                return;
            }
            sum += i+1;
            ans[i-1] = i+1;
            ans[i] = i;
            i++;
        }
        else 
        {
            ans[i-1] = i;
        }
    }

    for(int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << endll;
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