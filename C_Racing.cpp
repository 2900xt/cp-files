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

//comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{   
    ll N;
    cin >> N;
    vector<ll> d(N);
    for(ll i = 0; i < N; i++)
    {
        cin >> d[i];
    }

    vector<pair<ll, ll>> obstacles(N);
    for(ll i = 0; i < N; i++)
    {
        cin >> obstacles[i].first >> obstacles[i].second;
    }

    vector<pair<ll, ll>> dp(N+1);
    dp[0] = {0, 0};
    for(ll i = 1; i <= N; i++)
    {
        ll new_lo, new_hi;
        ll di = d[i-1];
        if(di == 0)
        {
            new_lo = dp[i-1].first;
            new_hi = dp[i-1].second;
        } 
        else if(di == 1)
        {
            new_lo = dp[i-1].first + 1;
            new_hi = dp[i-1].second + 1;
        } 
        else 
        {
            new_lo = dp[i-1].first;
            new_hi = dp[i-1].second + 1;
        }

        new_lo = max(new_lo, obstacles[i-1].first);
        new_hi = min(new_hi, obstacles[i-1].second);

        dp[i] = {new_lo, new_hi};
    }

    vector<ll> ans(N);
    ll h = dp[N].first; 
    for(ll i = N; i >= 1; i--)
    {
        ll prev_lo = dp[i-1].first;
        ll prev_hi = dp[i-1].second;
        int orig = d[i-1];
        if(orig == 0)
        {
            if(h < prev_lo || h > prev_hi)
            {
                cout << "-1" << endll;
                return;
            }
            ans[i-1] = 0;
        }
        
        if(orig == 1)
        {
            if(h-1 < prev_lo || h-1 > prev_hi)
            {
                cout << "-1" << endll;
                return;
            }
            ans[i-1] = 1;
            h -= 1;
        }
        
        if(orig == -1)
        {
            if(h-1 >= prev_lo && h-1 <= prev_hi)
            {
                ans[i-1] = 1;
                h -= 1;
            }
            else if(h >= prev_lo && h <= prev_hi)
            {
                ans[i-1] = 0;
            }
            else
            {
                cout << "-1" << endll;
                return;
            }
        }
    }
        
    for(ll x : ans) 
    {
        cout << x << " ";
    }
    cout << endll;
    
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