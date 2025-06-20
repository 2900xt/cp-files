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

const ll MAXK = 2e5+5;
ll largestBinUpTo[MAXK];
ll largestInd[MAXK];

void solve(int num_tc)
{
    dbg(num_tc)
    ll K; cin >> K;
    if(K == 1)
    {
        cout << "2\n0 0\n0 1\n";
        return;
    }

    ll n = 0;
    vector<ll> points{};
    while(K > 1)
    {
        dbg(K) dbg(largestBinUpTo[K])
        n += largestInd[K];
        points.push_back(largestInd[K]);
        K -= largestBinUpTo[K];
    }
    
    ll y = 0, x = 0;
    cout << n + (K != 0)*2 << endll;
    for(ll i = 0; i < points.size(); i++)
    {
        for(ll j = 0; j < points[i]; j++)
        {
            cout << x << " " << y << endll;
            x += 1;
        }
        y += 1;
    }
    dbg(points)

    if(K != 0)
    {
        cout << 100000000 << " " << 100000000 << endll;
        cout << -100000000 << " " << 100000000 << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");

    ll binomial = 0, ind = 0;
    for(int i = 0; i < MAXK; i++)
    {
        while(binomial < i)
        {
            ind++;
            binomial = (ind * (ind-1))/2;
        }
        
        largestBinUpTo[i] = ((ind-1) * (ind-2))/2;
        largestInd[i] = ind - 1;
    }

    ll T = 1; cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
