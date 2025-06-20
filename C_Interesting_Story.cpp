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
    int N; cin >> N;
    array<int, 5> totalFreq{};
    vector<array<int, 5>> freqs{};
    int ansSize = 0, freqCnt = 0;

    for(int i = 0; i < N; i++)
    {
        array<int, 5> cur{};
        string s; cin >> s;
        for(char c : s)
        {
            cur[c - 'a']++;
            totalFreq[c - 'a']++;
        }

        freqs.push_back(cur);
    }

    int mostFreq = 0;
    for(int i = 0; i < 5; i++)
    {
        if(totalFreq[mostFreq] < totalFreq[i])
        {
            mostFreq = i;
        }
    }

    freqCnt = totalFreq[freqCnt];
    for(int i = 0; i < 5; i++) ansSize += totalFreq[i];

    auto compFreq = [&](array<int, 5>&a, array<int, 5>&b)
    {
        return a[mostFreq] < b[mostFreq];
    };

    sort(all(freqs), compFreq);
    dbg(freqs)
    dbg(mostFreq)
    dbg(freqCnt) dbg(ansSize)

    while(2*freqCnt < ansSize)
    {
        if(freqs.empty())
        {
            cout << 0 << endll;
            return;
        }

        auto cur = freqs.back();
        for(int i = 0; i < cur.size(); i++)
        {
            if(i == mostFreq)
            {
                freqCnt -= cur[i];
            }
            
            ansSize -= cur[i];
        }

        freqs.pop_back();
    }

    cout << freqs.size() << endll;
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
