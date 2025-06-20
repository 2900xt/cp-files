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
//#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void sieve(vector<bool>& is_prime, ll n)
{
    is_prime[0] = is_prime[1] = false;
    for (ll i = 2; i <= n; i++) {
        if (is_prime[i] && (ll)i * i <= n) {
            for (ll j = i * i; j <= n; j += i)
                is_prime[j] = false;
        }
    }
}

int MAXN = 2e5+69;
vector<bool> is_prime(MAXN, true);
map<int, pair<int, int>> semiPrimes{};
void solve(int num_tc)
{
    int N; cin >> N;
    vector<ll> A(N);
    fillv(A, N);

    map<int, int> primes{}, cntSemis{};
    map<pair<int, int>, int> semis{};
    ll ans = 0, numPrimes = 0;;
    for(int i = 0; i < N; i++)
    {
        if(is_prime[A[i]])
        {
            ans += numPrimes + cntSemis[A[i]] - primes[A[i]];

            primes[A[i]]++;
            numPrimes++;
        }
        else if(semiPrimes.count(A[i]))
        {
            auto sp = semiPrimes[A[i]];
            ans += primes[sp.first] + primes[sp.second];
            if(sp.second == sp.first) ans -= primes[sp.first];

            ans += semis[sp];
            ans++;

            cntSemis[sp.first]++;
            if(sp.first != sp.second) cntSemis[sp.second]++;
            semis[sp]++;
        }
    }

    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    sieve(is_prime, MAXN-1);
    vector<ll> primes;
    for(int i = 0; i < MAXN; i++){
        if(is_prime[i]){
            primes.push_back(i);
        }
    }

    for(int i = 0; i < primes.size(); i++){
        for(int j = i; j < primes.size(); j++){
            ll semiPrime = primes[i] * primes[j];
            if(semiPrime > MAXN) break;

            semiPrimes[semiPrime] = {primes[i], primes[j]};
        }
    }

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
