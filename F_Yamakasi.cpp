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

ll subarraySum(vector<ll>& a, ll x)
{
    ll ans = 0;
    ll sum = 0;
    map<ll, ll> mp;
    mp[0] = 1;

    for(int i = 0; i < a.size(); i++)
    {
        sum += a[i];
        ans += mp[sum - x];
        mp[sum]++;
    }

    return ans;
}

void solve(int num_tc)
{
    ll n, s, x; cin >> n >> s >> x;
    vector<ll> a(n);
    fillv(a, n);

    ll ans = 0;
    ll start = 0;

    while (start < n) 
    {
        ll end = start;
        while (end < n && a[end] <= x)
        {
            end++;
        }

        // suabrray is [start, end)

        vector<ll> b(end - start);
        for(int i = start; i < end; i++)
        {
            b[i - start] = a[i];
        }

        ans += subarraySum(b, s);


        ll start2 = 0;
        while (start2 < b.size())
        {
            ll end2 = start2;
            while (end2 < b.size() && b[end2] < x)
            {
                end2++;
            }

            vector<ll> c(end2 - start2);
            for(int i = start2; i < end2; i++)
            {
                c[i - start2] = b[i];
            }

            ans -= subarraySum(c, s);

            start2 = end2 + 1;
        }

        start = end + 1;
    }

    cout << ans << endll;
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
