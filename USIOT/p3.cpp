#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        ll N; cin >> N;
        vector<ll> arr(N);
        for(int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        vector<ll> dp(N+1, 0);
        //dp[i] = max answer if we include up to first i elements inside array
        //we can form a subrarray between any (i, i-j) where j < i dp increase by max-min
        
        ll prevVal = 0;
        for(int i = 0; i < N; i++)
        {
            ll minVal = arr[i], maxVal = arr[i];
            dp[i+1] = dp[i];

            for(int j = 0; j <= i; j++)
            {
                minVal = min(minVal, arr[i-j]);
                maxVal = max(maxVal, arr[i-j]);
                dp[i+1] = max(dp[i+1], dp[i-j] + maxVal - minVal);
            }
        }

        cout << dp[N] << endll;
    }
}