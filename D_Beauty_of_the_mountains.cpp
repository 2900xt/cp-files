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
    int N, M, K; cin >> N >> M >> K;
    vector<vector<ll>> grid(N, vector<ll>(M));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> grid[i][j];
        }
    }

    vector<vector<ll>> type(N+1, vector<ll>(M+1, 0));
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < N; i++)
    {
        string s; cin >> s;
        for(int j = 0; j < M; j++)
        {
            int x = (s[j] == '1' ? 1 : -1);
            type[i+1][j+1] += x;
            type[i+1][j+1] += type[i][j+1] + type[i+1][j] - type[i][j];
            if(s[j] == '1')
            {
                sum1 += grid[i][j];
            }
            else 
            {
                sum2 += grid[i][j];
            }
        }
    }

    ll gcd = -1;
    for(int i = 0; i < N-K+1; i++)
    {
        for(int j = 0; j < M-K+1; j++)
        {
            ll sumRect = abs(type[i+K][j+K] - type[i+K][j] - type[i][j+K] + type[i][j]);
            if(gcd == -1) gcd = sumRect;
            else if(sumRect != 0) gcd = __gcd(gcd, sumRect);
        }
    }

    ll dif = abs(sum1 - sum2);
    if(gcd <= 0)
    {
        if(dif == 0) cout << "YES" << endll;
        else cout << "NO" << endll;
        return;
    }

    if(dif % gcd != 0)
    {
        cout << "NO" << endll;
        return;
    }
    cout << "YES" << endll;
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
