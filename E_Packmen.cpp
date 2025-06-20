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
//#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    ll N; cin >> N;
    string s; cin >> s;
    vector<ll> packmen, food;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '*')
        {
            food.push_back(i);
        }
        if(s[i] == 'P')
        {
            packmen.push_back(i);
        }
    }

    auto eval = [&](ll maxdist)
    {
        ll pPtr = 0, curpos = packmen[0], curdist = 0;
        ll eatenTil = -1;
        for(int fPtr = 0; fPtr < food.size(); fPtr++)
        {
            if(food[fPtr] <= eatenTil)
            {
                dbg(fPtr)
                dbg("EATEN")
                //already eaten
                continue;
            }

            dbg(fPtr)
            dbg(curdist) dbg(curpos) 
            curdist += abs(curpos - food[fPtr]);
            while(curdist > maxdist && pPtr < (packmen.size() - 1))
            {
                //move it up to next packmen
                pPtr++;
                dbg(pPtr)
                curpos = packmen[pPtr];
                curdist = abs(curpos - food[fPtr]);
            }

            eatenTil = packmen[pPtr];

            //if we moved back then we can eat all the ones in between.

            if(curdist > maxdist)
            {
                return false;
            }

            curpos = food[fPtr];
        }

        return true;
    };

    cout << eval(7) << endll;

    // ll hi = 1e12, lo = 1;
    // while(hi > lo)
    // {
    //     ll mid = (hi + lo) / 2;
    //     if(eval(mid))
    //     {
    //         hi = mid;
    //     }
    //     else
    //     {
    //         lo = mid + 1;
    //     }
    // }
    // cout << lo << endll;
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
