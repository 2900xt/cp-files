#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf ll(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

template <typename T>
inline void fillv(vector<T>& v, ll n) {
    for (ll i = 0; i < n; ++i) {
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

void solve(ll num_tc)
{
    ll N, M; cin >> N >> M;
    vector<vector<ll>> grid(N, vector<ll>(M));
    for(ll i = 0; i < N; i++) fillv(grid[i], M);

    ll ans = 0;
    vector<ll> sums(N);
    for(ll i = 0; i < N; i++)
    {
        ll rsum = 0, score = 0;
        for(ll j = 0; j < M; j++)
        {
            rsum += grid[i][j];
            score += rsum;
        }

        sums[i] = rsum;
        ans += score;
    }

    sort(all(sums));
    reverse(all(sums));

    for(int i = 0; i < N; i++)
    {
        ans += sums[i] * (M*N - M*(i+1));
    }

    cout << ans << endll;
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
