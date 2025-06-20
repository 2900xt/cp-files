#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// I love having gay sex lol
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9 + 7)
#define inf int(1e9 + 1)
#define INF ll(1e18 + 1)

template <typename T>
inline void fillv(vector<T> &v, int n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> v[i];
    }
}

inline void open(string name)
{
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

// comment to enable debugging
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
// edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

const ll MAXN = 1e6 + 69;
ll composite[MAXN + 69];
ll smallestPrime[MAXN + 69];

ll getAns(map<ll, ll, greater<ll>> &toDivide, ll k)
{
    vector<ll> factors;
    for (auto [p, c] : toDivide)
    {
        for (ll i = 0; i < c; i++)
        {
            factors.push_back(p);
        }
    }

    int n = factors.size();
    // dbg(factors)

    vector<pair<ll, ll>> dp(1 << n, {INF, INF});
    dp[0] = {1, 1};
    for (int mask = 0; mask < (1 << n); mask++)
    {
        if (dp[mask].first == INF)
            continue;

        for (int i = 0; i < n; i++)
        {
            if (!(mask & (1 << i)))
            {
                ll newWeight = factors[i] * dp[mask].second;
                ll newBins = dp[mask].first;
                if (newWeight > k)
                {
                    newWeight = factors[i];
                    newBins++;
                }

                ll newMask = mask | (1 << i);
                auto state = make_pair(newBins, newWeight);
                if (dp[newMask] > state)
                {
                    dp[newMask] = state;
                }
            }
        }
    }

    if (dp[(1 << n) - 1].second == 1)
    {
        dp[(1 << n) - 1].first--;
    }

    return dp[(1 << n) - 1].first;
}

void solve(int num_tc)
{
    ll x, y, k;
    cin >> x >> y >> k;

    map<ll, ll> pfaxX, pfacY;
    while (x > 1)
    {
        pfaxX[smallestPrime[x]]++;
        x /= smallestPrime[x];
    }

    while (y > 1)
    {
        pfacY[smallestPrime[y]]++;
        y /= smallestPrime[y];
    }

    map<ll, ll, greater<ll>> toDivide, toMultiply;
    for (auto [p, c] : pfaxX)
    {
        if (pfacY[p] < c)
        {
            toDivide[p] = c - pfacY[p];
        }
    }

    for (auto [p, c] : pfacY)
    {
        if (pfaxX[p] < c)
        {
            toMultiply[p] = c - pfaxX[p];
        }
    }

    bool possible = true;
    for (auto [p, c] : toDivide)
    {
        if (p > k && c > 0)
        {
            possible = false;
        }
    }

    for (auto [p, c] : toMultiply)
    {
        if (p > k && c > 0)
        {
            possible = false;
        }
    }

    if (!possible)
    {
        cout << -1 << endll;
        return;
    }

    cout << getAns(toDivide, k) + getAns(toMultiply, k) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");

    memset(composite, 0, sizeof(composite));
    for (ll i = 2; i <= MAXN; i++)
    {
        if (composite[i])
            continue;

        for (ll j = i; j <= MAXN; j += i)
        {
            smallestPrime[j] = i;
            composite[j] = i;
        }
    }

    ll T = 1;
    cin >> T;
    for (ll t = 0; t < T; t++)
    {
        solve(t + 1);
    }
}
