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

void solve(int num_tc)
{
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    fillv(a, N);
    fillv(b, M);

    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    vector<vector<pair<int, int>>> par(N + 1, vector<pair<int, int>>(M + 1, {-1, -1}));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + (a[i] == b[j]));

            if (dp[i + 1][j + 1] == dp[i][j + 1])
            {
                par[i + 1][j + 1] = {i, j + 1};
            }
            else if (dp[i + 1][j + 1] == dp[i + 1][j])
            {
                par[i + 1][j + 1] = {i + 1, j};
            }
            else
            {
                par[i + 1][j + 1] = {i, j};
            }
        }
    }

    cout << dp[N][M] << endll;
    vector<ll> ans{};
    pair<int, int> cur = {N, M};
    while (cur.first != 0 && cur.second != 0)
    {
        auto next = par[cur.first][cur.second];
        if (cur.first - next.first == 1 && cur.second - next.second == 1)
        {
            ans.push_back(a[next.first]);
        }
        cur = next;
    }

    reverse(all(ans));
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dbg("turn off debugging");
    ll T = 1;
    // cin >> T;
    for (ll t = 0; t < T; t++)
    {
        solve(t + 1);
    }
}
