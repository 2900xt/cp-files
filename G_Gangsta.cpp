#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if(!(cin >> t)) return 0;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        // Build prefix sums P[0..n]
        vector<ll> P(n+1);
        P[0] = 0;
        for(int i = 1; i <= n; i++){
            // map '1' -> +1, '0' -> -1
            P[i] = P[i-1] + (s[i-1] == '1' ? 1 : -1);
        }
        // Copy and sort
        vector<ll> v = P;
        sort(v.begin(), v.end());
        // Compute sum_abs = sum_{0 <= i < j <= n} (v[j] - v[i])
        ll prefix = 0;       // prefix sum of v[0..j-1]
        ll sum_abs = 0;
        for(int j = 0; j <= n; j++){
            // For index j in sorted array,
            // contribution = v[j] * j - sum_{i=0..j-1} v[i]
            sum_abs += v[j] * (ll)j - prefix;
            prefix += v[j];
        }
        // Sum of substring lengths: L = n(n+1)(n+2)/6
        ll L = (ll)n * (n + 1LL) * (n + 2LL) / 6LL;
        // Final answer = (L + sum_abs) / 2
        ll ans = (L + sum_abs) / 2;
        cout << ans << "\n";
    }

    return 0;
}
