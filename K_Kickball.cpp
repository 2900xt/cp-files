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
    ll N, M; cin >> N >> M;
    vector<array<ll, 3>> a(N);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 3; j++) cin >> a[i][j];
    }

    int yDirs[] = {1, 0, -1, 0};
    int xDirs[] = {0, 1, 0, -1};
    vector<ll> dir(N);
    vector<pair<ll, ll>> pos(N);

    map<ll, ll> xCnt{}, yCnt{};

    int aPtr = 0;
    for(int t = 0; t < M; t++)
    {
        while(aPtr < N && a[aPtr][2] <= t)
        {
            pos[aPtr] = {a[aPtr][0], a[aPtr][1]};
            xCnt[pos[aPtr].first]++;
            yCnt[pos[aPtr].second]++;
            aPtr++;
        }        

        for(int i = 0; i < aPtr; i++)
        {
            auto [x, y] = pos[i];
            //rotate the jit
            switch(dir[i])
            {
                case 0:
                case 2:
                    //going north or south currently
                    //look to east or west (y lines)
                    if(yCnt[y] % 2 == 0)
                    {
                        //odd number if excluding themselves is even
                        //change dir
                        dir[i] = (dir[i]+1)%4;
                    }
                    break;
                case 1:
                case 3:
                    //going east or west 
                    //look to north or south (x lines)
                    if(xCnt[x] % 2 == 0)
                    {
                        //odd number if excluding themselves is even
                        //change dir
                        dir[i] = (dir[i]+1)%4;
                    }
                    break;

            }

            //move the jit
        }

        for(int i = 0; i < aPtr; i++)
        {
            xCnt[pos[i].first]--;
            yCnt[pos[i].second]--;
            pos[i].first += xDirs[dir[i]];
            pos[i].second += yDirs[dir[i]];
            xCnt[pos[i].first]++;
            yCnt[pos[i].second]++;
        }
    }

    for(int i = 0; i < N; i++)
    {
        cout << pos[i].first << " " << pos[i].second << endll;
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1; 
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
