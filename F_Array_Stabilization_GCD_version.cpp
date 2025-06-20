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

class SegTree {
    public:
      typedef int T;                // Type alias for the tree's value type
      static constexpr T unit = 0; // Identity element for the operation
  
      /**
       * @brief Combines two values using the tree's operation
       * @param a First value
       * @param b Second value
       * @return Result of combining a and b
       */
      T f(T a, T b) { return gcd(a, b); }
  
      vector<T> s; // Internal tree storage
      ll n;        // Size of the original array
  
      /**
       * @brief Constructs a segment tree
       * @param n Size of the array
       * @param def Default value for initialization (default = unit)
       */
      SegTree(ll n = 0, T def = unit) : s(2 * n, def), n(n) {}
  
      /**
       * @brief Updates a single position in the tree
       * @param pos Position to update (0-based)
       * @param val New value
       * Time complexity: O(log n)
       */
      void update(ll pos, T val) {
          for (s[pos += n] = val; pos /= 2;)
              s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
      }
  
      /**
       * @brief Builds the tree from an array
       * @param v Input array
       * Time complexity: O(n)
       */
      void build(vector<T> &v) {
          for (ll i = 0; i < (ll)v.size(); i++)
              update(i, v[i]);
      }
  
      /**
       * @brief Queries a range [b, e)
       * @param b Beginning of range (inclusive)
       * @param e End of range (exclusive)
       * @return Result of combining all elements in the range
       * Time complexity: O(log n)
       */
      T query(ll b, ll e) {
          T ra = unit, rb = unit;
          for (b += n, e += n; b < e; b /= 2, e /= 2) {
              if (b % 2)
                  ra = f(ra, s[b++]);
              if (e % 2)
                  rb = f(s[--e], rb);
          }
          return f(ra, rb);
      }
  };

void solve(int num_tc)
{
    int N; cin >> N;
    vector<int> arr(N);
    fillv(arr, N);

    vector<int> circle = arr;
    circle.insert(circle.end(), arr.begin(), arr.end());

    SegTree st(2*N);
    st.build(circle);

    auto eval = [&](int window)
    {
        int ans = -1;
        for(int i = 0; i < N; i++)
        {
            int cur = st.query(i, i+window);
            if(ans == -1)
            {
                ans = cur;
            }

            if(ans != cur) return false;
        }

        return true;
    };

    ll hi = N, lo = 1;
    while(hi > lo)
    {
        ll mid = (hi + lo) / 2;
        if(eval(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    cout << hi-1 << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
