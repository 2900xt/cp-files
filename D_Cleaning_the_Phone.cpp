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

void solve(int num_tc)
{
    ll N, M; cin >> N >> M;
    vector<int> one, two, a(N);
    fillv(a, N);

    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        if(x == 1) {
            one.push_back(a[i]);
        }
        else {
            two.push_back(a[i]);
        }
    }

    sort(all(one));
    sort(all(two));
    reverse(all(one));
    reverse(all(two));

    vector<ll> twoPref(two.size() + 1);
    for(int i = 0; i < two.size(); i++)
    {
        twoPref[i+1] = twoPref[i] + two[i];
    }

    ll cur = 0, ans = 1e18;
    for(int a = 0; a <= one.size(); a++)
    {
        ll rem = max(0LL, M - cur);
        ll lb = lower_bound(all(twoPref), rem) - twoPref.begin();
        if(a != one.size()) cur += one[a];

        if(lb == twoPref.size()) continue;
        ans = min(ans, (a) + (2*lb));
    }

    if(ans == 1e18)
    {
        cout << -1 << endll;
        return;
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
