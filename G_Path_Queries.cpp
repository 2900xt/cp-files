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


struct DSU {
    vector<ll> e;
  DSU(ll N)
  {
      e = vector<ll>(N, -1); 
  }

    void init(ll N) { 
      e = vector<ll>(N, -1); 
  }

    ll get(ll x) { 
      return e[x] < 0 ? x : e[x] = get(e[x]); 
  }

    bool sameSet(ll a, ll b) {
      return get(a) == get(b); 
  }

    ll size(ll x) {
      return -e[get(x)]; 
  }

    bool unite(ll x, ll y) { // union by size
      x = get(x), y = get(y);
      if (x == y)
        return 0;
      if (e[x] > e[y])
        swap(x, y);
  
      e[x] += e[y];
      e[y] = x;
      return 1;
    }
};

void solve(int num_tc)
{
    int N, M; cin >> N >> M;
    vector<array<ll, 3>> edges{};
    for (int i = 0; i < N - 1; ++i) {
        int u, v; ll w; cin >> u >> v >> w;
        u--; v--;
        edges.push_back({w, u, v});
        //cerr << u << " " << v << " " << w << endll;
    }

    sort(all(edges));

    vector<array<ll, 2>> queries{};
    vector<ll> ans(M);
    for (int i = 0; i < M; ++i) {
        int q; cin >> q;
        queries.push_back({q, i});
    }

    sort(all(queries));

    DSU dsu(N+1);
    ll ePtr = 0;
    ll curAns = 0;

    for(int i = 0; i < M; i++)
    {
        while(ePtr < N-1 && edges[ePtr][0] <= queries[i][0])
        {
            //get current componet sizes
            ll u = dsu.size(edges[ePtr][1]);
            ll v = dsu.size(edges[ePtr][2]);
            curAns -= (u*(u-1))/2;
            curAns -= (v*(v-1))/2;

            dsu.unite(edges[ePtr][1], edges[ePtr][2]);
            u += v;
            curAns += (u*(u-1))/2;
            ePtr++;
        }

        ans[queries[i][1]] = curAns;
    }

    for(int i = 0; i < M; i++)
    {
        cout << ans[i] << " ";
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
