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
    vector<vector<int>> observations(M);
    for(int i = 0; i < M; i++)
    {
        int num; cin >> num;
        observations[i] = vector<int>(num);
        for(int j = 0; j < num; j++)
        {
            int x; cin >> x;
            x--;
            observations[i][j] = x;
        }
    }


    auto get_lex_min_topsort = [&](int X)
    {
        //prepare the graph
        vector<vector<int>> adj(N);
        vector<int> indeg(N);
        for(int i = 0; i < X; i++)
        {
            for(int j = 0; j < (int)observations[i].size() - 1; j++)
            {
                adj[observations[i][j]].push_back(observations[i][j+1]);
                indeg[observations[i][j+1]]++;
            }
        }

        priority_queue<int, vector<int>, greater<int>> khanQ{};
        for(int i = 0; i < N; i++)
        {
            if(indeg[i] == 0)
            {
                khanQ.push(i);
            }
        }

        vector<int> topSort{};
        while(!khanQ.empty())
        {
            int cur = khanQ.top();
            khanQ.pop();

            topSort.push_back(cur);

            for(int n : adj[cur])
            {
                indeg[n]--;
                if(indeg[n] == 0)
                {
                    khanQ.push(n);
                }
            }
        }

        return topSort;
    };

    int hi = M, lo = 0;
    while(hi > lo)
    {
        int mid = (hi + lo) / 2;
        vector<int> ts = get_lex_min_topsort(mid);
        if(ts.size() == N)
        {
            lo = mid + 1;
        }
        else 
        {
            hi = mid;
        }
    }

    vector<int> ts = get_lex_min_topsort(lo - 1);
    for(int i = 0; i < ts.size(); i++)
    {
        cout << ts[i] + 1;
        if(i != ts.size() - 1)
        {
            cout << " ";
        }
    }
}

int32_t main()
{
    open("milkorder");
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  
    dbg("turn off debugging");
    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
