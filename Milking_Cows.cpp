/*
ID: tahakaz1
LANG: C++
TASK: milk2
*/
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

const int MAXN = 1e6+69;
int arr[MAXN];

void solve(int num_tc)
{
    int N; cin >> N;
    for(int i =0; i < N; i++)
    {
        int a, b; cin >> a >> b;
        arr[a]++;
        arr[b+1]--;
    }

    int ans1 = 0, ans0 = 0, cur = 0;
    for(int t = 1; t < MAXN; t++)
    {
        arr[t] += arr[t-1];
        if(arr[t] > 0 != arr[t-1] > 0)
        {
            //switch signs lol
            if(arr[t] > 0)
            {
                ans0 = max(ans0+1, cur);
            }
            else
            {
                ans1 = max(ans1-1, cur);
            }
            cur = 0;
        }

        cur++;
    }

    cout << ans1 << " " << ans0 << endll;
}

int32_t main()
{
    open("milk2");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
