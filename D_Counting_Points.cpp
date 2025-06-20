#include <algorithm>
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

ll getHeight(ll r, ll x, ll cur)
{
    return sqrt(r*r - (cur-x)*(cur-x));
}

void solve(int num_tc)
{
    ll N, M; cin >> N >> M;
    vector<ll> centers(N), rads(N);
    fillv(centers, N);
    fillv(rads, N);

    vector<pair<ll, ll>> circles{};
    for(int i = 0; i < N; i++)
    {
        circles.push_back({centers[i] - rads[i], i});
    }

    sort(all(circles));
    reverse(all(circles));

    ll ans = 0;
    while(!circles.empty())
    {
        auto [start, cur] = circles.back();
        circles.pop_back();

        set<ll> active{};
        active.insert(cur);

        ll x = start;
        while(!active.empty()) 
        {
            while(!circles.empty() && x > circles.back().first)
            {
                int idx = circles.back().second;
                circles.pop_back();
                active.insert(idx);
            }

            set<int> toErase{};
            ll maxHeight = 0;
            for(int idx : active)
            {
                if(rads[idx] + centers[idx] < x)
                {
                    toErase.insert(idx);
                }
                else 
                {
                    ll height = getHeight(rads[idx], centers[idx], x);
                    maxHeight = max(maxHeight, height);
                }
            }

            for(int idx : toErase) 
            {
                active.erase(idx);
            }

            ans += 2*maxHeight + (!active.empty());
            x++;
        }
    }

    cout << ans << endll;
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
