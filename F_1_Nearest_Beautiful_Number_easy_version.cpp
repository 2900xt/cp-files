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

vector<ll> ansOne, ansTwo{};

void solve(int num_tc)
{
    ll N, K; cin >> N >> K;
    if(K == 1) cout << *lower_bound(all(ansOne), N) << endll;
    else cout << *lower_bound(all(ansTwo), N) << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    
    for(int digit1 = 0; digit1 <= 9; digit1++)
    {
        for(int digit2 = digit1; digit2 <= 9; digit2++)
        {
            for(int mask = 0; mask < (1 << 11); mask++)
            {
                for(int lz = 0; lz < 11; lz++) 
                {
                    string numStr = "";
                    for(int i = 0; i < 11; i++)
                    {
                        if(i <= lz)
                        {
                            numStr.push_back('0');
                            continue;
                        }

                        if(mask & (1 << i))
                        {
                            numStr.push_back(digit1 + '0');
                        }
                        else 
                        {
                            numStr.push_back(digit2 + '0');
                        }
                    }

                    ll num = stoll(numStr);
                    if(digit1 == digit2)
                    {
                        ansOne.push_back(num);
                    }

                    ansTwo.push_back(num);
                }
            }
        }
    }

    sort(all(ansOne));
    sort(all(ansTwo));
    
    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++)
    {
        solve(t+1);
    }
}
