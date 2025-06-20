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

ll invMod(ll x) {
    if (x <= 1) {
      return x;
    }
    return MOD - MOD / x * invMod(MOD % x) % MOD;
  }

template<typename T>
T binom(T n, T k, std::vector<T>& fact, std::vector<T>& invfact, T mod, T size = 3e5){
	if(mod == -1){
		mod = MOD;
	}
	if(fact.size() < size + 1){
		fact.resize(size + 1);
		invfact.resize(size + 1);
		fact[0] = 1;
		for(int i = 1; i < fact.size(); i++){
			fact[i] = (fact[i - 1] * i) % mod;
		}
		invfact[size] = invMod(fact[size]);
		for(int i = size - 1; i >= 0; i--){
			invfact[i] = invfact[i + 1] * (i + 1) % mod;
		}
	}

	return ((fact[n] * invfact[k]) % MOD * invfact[n - k]) % MOD;
}

vector<ll> fact, invFact;

void solve(int num_tc)
{
    int N, K; cin >> N >> K;
    map<ll, ll> freq{}, chosen{};
    vector<int> arr{};
    for(int i = 0; i < N; i++)
    {
        int x; cin >> x;
        arr.push_back(x);
        freq[x]++;
    }

    sort(all(arr));
    reverse(all(arr));
    ll last = 0;

    for(int i; i < K; i++)
    {
        chosen[arr[i]]++;
        last = arr[i];
    }

    cout << binom(freq[last], chosen[last], fact, invFact, MOD) << endll;
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
