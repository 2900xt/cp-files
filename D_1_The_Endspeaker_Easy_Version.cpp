#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

    
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int n, m; cin >> n >> m;
        vector<int> a(n);
        vector<int> b(m);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < m; i++) cin >> b[i];


        //dp[i][j] = min operations to remove 1..i from a and k=j
        vector<vector<ll>> dp(n+1, vector<ll>(m, 1e18));
        for(int i = 0; i < m; i++) dp[0][i] = 0;

        //type 1: (increase k by 1)
        //dp[i+1][j] = dp[i+1][j-1]
    
        //type 2: bin search on index z s.t. sum of a_z...a_i <= b_j.
        //dp[i+1][j] = dp[z][j] + (m - j)

        //answer is max(dp[n][j])
        vector<ll> prefA(n+1, 0);
        for(int i = 0; i < n; i++) prefA[i+1] = prefA[i] + a[i];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(j > 0) dp[i+1][j] = dp[i+1][j-1];
                ll hi = i+1, lo = 0;
                while(lo < hi)
                {
                    ll mid = (hi + lo) / 2;
                    if(prefA[i+1] - prefA[mid] > b[j]) lo = mid + 1;
                    else hi = mid;
                }
                //cerr << i << " " << b[j] << " " << hi << endll;
                dp[i+1][j] = min(dp[i+1][j], dp[hi][j] + (m-j-1));

                //cerr << dp[i+1][j] << " ";
            }
            //cerr << endll;
        }
        //cerr << endll;

        ll ans = 1e18;
        for(int j = 0; j < m; j++) ans = min(ans, dp[n][j]);

        if(ans == 1e18) cout << -1 << endll;
        else cout << ans << endll;
    }

    return 0;
}
