#include <cmath>
#include <string>
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

void solve(int num_tc)
{
    int N; cin >> N;
    if(N == 1)
    {
        cout << 1 << endll;
        return;
    }

    string s = "169";
    for(int i = 0; i < N - 3; i++)
    {
        s += '0';
    }
    //zeroes = (N-2)/2

    //1000069 = n odd
    //100003 .. 130000
    //300001 .. 310000
    //140000
    
    vector<ll> perfects{};
    string digits = s;

    sort(all(digits));
    do
    {
        ll num = stoll(digits);
        if(digits.front() == '0') continue;
        if(ll(sqrt(num))*ll(sqrt(num)) == num)
        {
            perfects.push_back(num);
        }
    
    } while(next_permutation(all(digits)));

    dbg(perfects);
    dbg(perfects.size());
    
    if(perfects.size() >= N)
    {
        cout << s << endll;
    }
    
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
