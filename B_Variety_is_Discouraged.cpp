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
#define dbg(x)

#ifndef dbg
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endl;
//edit for specific DS
#include "cp-templates/Debugging/alldebug.h"
#endif

void solve(int num_tc)
{
    int N; cin >> N;
    vector<int> a(N);
    fillv(a, N);

    vector<int> sufScore(N+1);
    map<int, int> cnt{};
    for(int i = N-1; i >= 0; i--)
    {
        cnt[a[i]]++;
        sufScore[i] = sufScore[i+1];
        if(cnt[a[i]] != 1)
        {
            sufScore[i]++;
        }
    }

    if(sufScore[0] == 0)
    {
        cout << "1" << " " << N << endll;
        return;
    }

    int window = sufScore[0];
    int ans = sufScore[0], ansL = -1, ansR = -1, ansLen = N;
    int score = sufScore[0], curR = 0, curL = 0;
    while(curR < N)
    {
        cnt[a[curR]]--;
        if(cnt[a[curR]] >= 1)
        {
            score--;
        }

        while(curL < curR && score < window)
        {
            cnt[a[curL]]++;
            if(cnt[a[curL]] > 1)
            {
                score++;
            }
            curL++;
        }

        int len = N - (curR - curL - 1);

        if(len <= ansLen && score == window)
        {
            ansL = curL;
            ansR = curR;
            ansLen = curR - curL;
        }

        curR++;
    }

    if(ansL == -1)
    {
        cout << 0 << endll;
        return;
    }

    cout << ansL + 1 << " " << ansR + 1 << endll;
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
