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
    string s; cin >> s;
    int N = s.length();
    vector<vector<int>> isPalindrome(N, vector<int>(N));
    for(int i = 0; i < N; i++)
    {
        isPalindrome[i][i] = true;
        int r = i+1, l = i-1;
        while(r < N && l >= 0)
        {
            isPalindrome[l][r] = isPalindrome[l+1][r-1] && s[r] == s[l]; 
            r++;
            l--;
        }
    }

    for(int i = 0; i < N-1; i++)
    {
        int r = i+1, l = i;
        if(s[r] != s[l]) continue;

        isPalindrome[l][r] = true;
        l--; r++;
        while(r < N && l >= 0)
        {
            isPalindrome[l][r] = isPalindrome[l+1][r-1] && s[r] == s[l]; 
            r++;
            l--;
        }
    }


    vector<vector<int>> psum(N+1, vector<int>(N+1));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            psum[i+1][j+1] = isPalindrome[i][j] + psum[i+1][j] + psum[i][j+1] - psum[i][j];
        }
    }


    int Q; cin >> Q;
    for(int q = 0; q < Q; q++)
    {
        int l, r; cin >> l >> r;
        int ans = psum[r][r] - psum[r][l-1] - psum[l-1][r] + psum[l-1][l-1];
        cout << ans << endll;
    }
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
