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
    vector<ll> a(N), b(M);
    fillv(a, N);
    fillv(b, M);

    sort(all(b));

    a[0] = min(a[0], b[0] - a[0]);

    for(int i = 1; i < N; i++)
    {   
        bool found = false;
        ll minVal = 1e9;

        ll lb = lower_bound(all(b), a[i-1] + a[i]) - b.begin();

        if(lb != M)
        {
            found = true;
            minVal = min(minVal, b[lb] - a[i]);
        }
        
        if(a[i] >= a[i-1])
        {
            found = true;
            minVal = min(minVal, a[i]);
        }

        if(!found)
        {
            cout << "NO" << endll;
            return;
        }

        a[i] = minVal;
    }

    cout << "YES" << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
