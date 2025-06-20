#include <iostream>
#include <queue>
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
    int N, M; cin >> N >> M;
    int A, B; cin >> A >> B;
    vector<int> crackers(M);
    fillv(crackers, M);
    sort(all(crackers));

    dbg(num_tc)

    auto possible2 = [&](int num)
    {
        int numPossible = abs(A - B) + 1;
        if(num > numPossible || num > M) return false;
 
        vector<int> jits{};
        for(int i = 0; i < num; i++) jits.push_back(crackers[i]);
        sort(jits.rbegin(), jits.rend());
 
        priority_queue<int> explosions{};
        for(int i = 0; i < num; i++) 
        {
            explosions.push(-(jits[i]+i+1));
        }
 
        int a = A, b = B, t = num;
        int spacesToGo;
        if(a > b)
        {
            b += num - 1;
            spacesToGo = N - a + abs(a - b) - 1;
        }
        else
        {
            b -= num - 1;
            spacesToGo = a + abs(a - b) - 1;
        }
 
        while(!explosions.empty())
        {
            if(-explosions.top() >= t + spacesToGo)
            {
                return false;
            }
 
            explosions.pop();
        }
 
        return explosions.empty();
    };

    auto possible = [&](int num)
    {
        if(num > M) return false;

        vector<int> jits{};
        for(int i = 0; i < num; i++) jits.push_back(crackers[i]);
        sort(jits.rbegin(), jits.rend());

        priority_queue<int> explosions{};
        for(int i = 0; i < num; i++) 
        {
            explosions.push(-(jits[i]+i+1));
        }

        int a = A, b = B, t = num;
        int spacesToGo;
        if(a > b)
        {
            b += num - 1;
            spacesToGo = N - a + abs(a - b) - 1;
        }
        else
        {
            b -= num - 1;
            spacesToGo = a + abs(a - b) - 1;
        }

        while(!explosions.empty())
        {
            if(-explosions.top() >= t + spacesToGo)
            {
                return false;
            }

            explosions.pop();
        }

        return explosions.empty();
    };

    ll hi = M+69, lo = 0;
    while(hi > lo)
    {
        ll mid = (hi+lo)/2;
        bool pos = N*M <= 5e8 ? possible2(mid) : possible(mid); 
        if(!pos)
        {
            hi = mid;
        }
        else 
        {
            lo = mid + 1;
        }
    }

    cout << lo-1 << endll;
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
