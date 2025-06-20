#include <queue>
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
    vector<ll> a(N), d(N);
    fillv(a, N);
    fillv(d, N);

    vector<array<ll, 3>> _pq{};
    for(int i = 0; i < N; i++)
    {
        if(a[i] == 0) continue;
        _pq.push_back({i-d[i], i+d[i], a[i]});
    }

    sort(all(_pq));

    auto evalZ = [&](ll z)
    {
        int ptr = 0;
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> inSubarray{};
        for(int i = 0; i < N; i++)
        {
            while(ptr != _pq.size() && _pq[ptr][0] <= i)
            {
                inSubarray.push({_pq[ptr][1], _pq[ptr][0], _pq[ptr][2]});
                ptr++;
            }

            if(!inSubarray.empty() && inSubarray.top()[0] < i)
            {
                return false;
            }

            ll cur = 0;
            while(!inSubarray.empty()) 
            {
                auto [r, l, v] = inSubarray.top();
                inSubarray.pop();

                ll num = min(v, max(0ll, z - cur));
                v -= num;
                cur += num;
                if(v != 0)
                {
                    inSubarray.push({r, l, v});
                    break;
                }
            }
        }

        if(!inSubarray.empty()) return false;
        return true;
    };

    ll hi = 1e15, lo = 0;
    while(hi > lo)
    {
        ll mid = (hi+lo)/2;
        if(!evalZ(mid))
        {
            lo = mid+1;
        }
        else 
        {
            hi = mid;
        }
    }
    cout << lo << endll;
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
