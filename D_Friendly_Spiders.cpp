#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef vector<bool> vb;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf ll(1e9+1)
#define INF ll(1e18+1)
#define EPS ld(1e-9)

template <typename T>
inline void fillv(vector<T>& v, ll n) {
    for (ll i = 0; i < n; ++i) {
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

const ll MAXN = 300069;
vector<ll> factors[MAXN];
vector<bool> is_prime(MAXN+1, true);

void solve(ll num_tc)
{
    ll N; cin >> N;
    vector<ll> a(N);

    fillv(a, N);
    ll s, t; cin >> s >> t;
    s--; t--;

    sieve(is_prime, MAXN);
    vector<ll> primes{1};
    for(ll i = 2; i <= MAXN; i++)
    {
        if(is_prime[i]) primes.push_back(i);
    }
    
    vector<vector<ll>> actualFactors(N);
    for(ll i = 0; i < N; i++)
    {
        for(ll j = 0; primes[j]*primes[j] <= a[i]; j++)
        {
            if(a[i] % primes[j] == 0)
            {
                if(primes[j] != 1) 
                {
                    factors[primes[j]].push_back(i);
                    actualFactors[i].push_back(primes[j]);
                }

                if(primes[j]*primes[j] != a[i]) 
                {
                    factors[a[i]/primes[j]].push_back(i);
                    actualFactors[i].push_back(a[i]/primes[j]);
                }
            }
        }
    }

    vector<ll> dist(N, inf), parents(N, -1);
    dist[s] = 0;
    
    queue<ll> q;
    q.push(s);


    while(!q.empty())
    {
        ll cur = q.front();
        q.pop();
        for(ll f : actualFactors[cur])
        {
            for(ll i : factors[f])
            {
                if(dist[i] > dist[cur] + 1)
                {
                    dist[i] = dist[cur] + 1;
                    parents[i] = cur;
                    q.push(i);
                }
            }
        }
    }

    if(dist[t] == inf) 
    {
        cout << -1 << endll;
        return;
    }
    
    cout << dist[t] + 1 << endll;
    vector<ll> ans;
    ll x = t;
    while(x != s)
    {
        ans.push_back(x+1);
        x = parents[x];
    }
    ans.push_back(s+1);
    reverse(all(ans));
    for(ll i : ans) cout << i << " ";
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
