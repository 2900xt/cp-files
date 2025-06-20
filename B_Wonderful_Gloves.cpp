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
        int n, k; cin >> n >> k;
        vector<ll> l(n), r(n);
        vector<ll> mx(n), mn(n);
        for(int i = 0; i < n; i++) cin >> l[i];
        for(int i = 0; i < n; i++) cin >> r[i];
        for(int i = 0; i < n; i++) mx[i] = max(l[i], r[i]), mn[i] = min(l[i], r[i]);
        sort(mx.rbegin(), mx.rend());
        sort(mn.rbegin(), mn.rend());
        ll ans = accumulate(mx.begin(), mx.end(), 0LL) + accumulate(mn.begin(), mn.begin() + k - 1, 0LL) + 1;
        cout << ans << endll;
    }
    return 0;
}
