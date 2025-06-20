#include <deque>
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
    int N; cin >> N;
    deque<int> a{}, og;
    for(int i = 0; i < N; i++)
    {
        int x; cin >> x;
        a.push_back(x);
    }

    og = a;

    deque<int> ans{};
    while(!a.empty())
    {
        if(a.front() < a.back())
        {
            ans.push_front(a.front());
            a.pop_front();
        }
        else
        {
            ans.push_back(a.back());
            a.pop_back();
        }
    }

    deque<int> cp = ans;

    while(!ans.empty())
    {
        if(ans.front() < ans.back())
        {
            a.push_front(ans.front());
            ans.pop_front();
        }
        else
        {
            a.push_back(ans.back());
            ans.pop_back();
        }
    }
    
    vector<int> a1{};
    a1.insert(a1.end(), all(a));
    vector<int> a2{};
    a2.insert(a2.end(), all(og));
    

    dbg(a1);
    dbg(a2)
    bool fnd1 = true, fnd2 = true;
    for(int i = 0; i < N; i++)
    {
        if(a1[i] != a2[i])
        {
            fnd1 = false;
        }

        if(a1[i] != a2[(i+1)%N])
        {
            fnd2 = false;
        }
    }

    //simulate  
    if(!fnd1 && !fnd2)
    {
        cout << -1 << endll;
    }
    else 
    {
        for(int i : cp)
        {
            cout << i << " ";
        }
        cout << endll;
    }
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
