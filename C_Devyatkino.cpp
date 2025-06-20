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

vector<ll> sums[10];
ll nines[] = {9, 99, 999, 9999, 99999, 999999, 9999999, 99999999, 999999999};

void precompute(ll len, ll prev, ll ops)
{
    if(len == 9)
    {
        sums[ops].push_back(prev);
        return;
    }

    if(ops == 9)
    {
        sums[ops].push_back(prev);
        return;
    }

    for(ll i = 0; i < 9 - ops; i++)
    {
        precompute(len + 1, prev + i * nines[len], ops + i);
    }
}

unordered_map<ll, ll> prevs{};

void solve()
{
    ll N; cin >> N;
    if(prevs.count(N))
    {
        cout << prevs[N] << endll;
        return;
    }

    for(ll ans = 0; ans < 9; ans++)
    {
        for(ll j : sums[ans])
        {
            ll M = N + j;
            if(j > 100*N) continue;

            string s = to_string(M);
            if(s.find('7') != string::npos)
            {
                prevs[N] = ans;
                cout << ans << endll;
                return;
            }
        }
    }

    prevs[N] = 9;
    cout << 9 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    precompute(0, 0, 0);
    ll T = 1;
    cin >> T;

    for(ll t = 0; t < T; t++)
    {
        solve();
    }
}
