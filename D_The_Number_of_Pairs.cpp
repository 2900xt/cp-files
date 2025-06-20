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
const int MAXN = 2e7+69;
int minPrimeDivisor[MAXN];
int numPrimeDivisors[MAXN];

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");

    minPrimeDivisor[1] = 1;
    for(int i = 2; i < MAXN; i++)
    {
        if(minPrimeDivisor[i] == 0)
        {
            for(int j = i; j < MAXN; j += i)
            {
                if(minPrimeDivisor[j] == 0)
                {
                    minPrimeDivisor[j] = i;
                }
            }
        }
    }

    for(int i = 2; i < MAXN; i++)
    {
        int j = i / minPrimeDivisor[i];
        if(minPrimeDivisor[i] != minPrimeDivisor[j]) numPrimeDivisors[i] = numPrimeDivisors[j] + 1;
        else numPrimeDivisors[i] = numPrimeDivisors[j];
    }

    ll T = 1; cin >> T;
    for(ll t = 0; t < T; t++)
    {
        ll C, D, X; cin >> C >> D >> X;
        ll ans = 0;
        for(ll g = 1; g*g <= X; g++)
        {
            if(X % g != 0) continue;

            ll k1 = g + D, k2 = X/g + D;
            if(k1 % C == 0)
            {
                ll k = k1 / C;
                ans += (1LL << numPrimeDivisors[k]);
            }

            if(k2 % C == 0 && g*g != X)
            {
                ll k = k2 / C;
                ans += (1LL << numPrimeDivisors[k]);
            }
        }

        cout << ans << endll;
    }
}
