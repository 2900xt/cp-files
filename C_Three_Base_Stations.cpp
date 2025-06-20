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
    vector<int> arr(N);
    fillv(arr, N);
    sort(all(arr));

    auto possible = [&](ll d)
    {
        vector<ld> pos{};
        ll cur = -1e10;
        for(int i = 0; i < N; i++)
        {
            if(arr[i] - cur > d)
            {
                cur = arr[i];
                pos.push_back(cur + d/2.0);
            }

            if(pos.size() > 3) return false;
        }
        
        return true;
    };

    ll hi = 2e9, lo = 0;
    while(hi > lo)
    {
        ll mid = (hi+lo)/2;
        if(possible(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }

    if(abs(hi) < 1e-2)
    {
        hi = 0;
    }

    vector<ld> pos{0, 0, 0};
    ll cur = -1e10;
    for(int i = 0; i < N; i++)
    {
        if(arr[i] - cur > hi)
        {
            cur = arr[i];
            pos.insert(pos.begin(), cur + (hi/2.0));
        }
    }

    cout << fixed << setprecision(6);
    cout << hi/2.0 << endll;
    cout << pos[0] << " " << pos[1] << " " << pos[2] << endll;
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
