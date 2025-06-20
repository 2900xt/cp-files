#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
// I love having gay sex lol
using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll, ll> pll;

#define endll '\n'

#define all(x) (x).begin(), (x).end()

#define MOD ll(1e9+7)
#define inf int(1e9+1)
#define INF ll(1e18+1)

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
    int n, a, b; cin >> n >> a >> b;
    ll val = 1;

    if(a == 0 && b == 0)
    {
        for(int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << endll;
        return;
    }

    if(a == n-1 && b == 0)
    {
        cout << -1 << endll;
        return;
    }

    if(b == 0)
    {
        cout << val << " ";
        n--;
    }

    for(int i = 0; i <= b; i++)
    {
        cout << val << " ";
        if(i != b) val *= 2;
    }

    //val++;

    for(int i = 0; i < a; i++)
    {
        val++;
        cout << val << " ";
    }

    for(int i = 0; i < n-a-b-1; i++)
    {
        cout << val << " ";
    }

    cout << endll;
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
