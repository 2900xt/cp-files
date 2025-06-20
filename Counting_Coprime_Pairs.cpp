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
    int N; cin >> N;
    int MAXA = 1e6+69;
    vector<int> minPrimeDivisor(MAXA, -1);
    minPrimeDivisor[1] = minPrimeDivisor[0] = 1;
    for(int i = 2; i < MAXA; i++)
    {
        if(minPrimeDivisor[i] != -1) continue;

        for(int j = i; j < MAXA; j += i)
        {
            if(minPrimeDivisor[j] == -1)
            {
                minPrimeDivisor[j] = i;
            }
        }
    }

    map<int, int> primeFreqs{};
    vector<int> arr(N);
    for(int i = 0; i < N; i++)
    {
        cin >> arr[i];
        int x = arr[i];
        set<int> pdubs{};

        while(x != 1)
        {
            pdubs.insert(minPrimeDivisor[x]);
            x /= minPrimeDivisor[x];
        }

        for(int pdub : pdubs) 
        {
            primeFreqs[pdub]++;
        }
    }

    ll ans = 0;
    for(int i = 0; i < N; i++)
    {
        int x = arr[i];
        set<int> pdubs{};

        while(x != 1)
        {
            pdubs.insert(minPrimeDivisor[x]);
            x /= minPrimeDivisor[x];
        }

        for(int pdub : pdubs) 
        {
            primeFreqs[pdub]++;
        }
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
