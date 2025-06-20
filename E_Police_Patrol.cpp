#pragma GCC optimize("Ofast")

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
    ll n, m; cin >> n >> m;
    vector<ll> pos(n);

    for(int i = 0; i < n; i++)
    {
        cin >> pos[i];
    }

    sort(pos.begin(), pos.end());

    auto eval = [&](ll ctr, int ind) 
    {
        ll ans = 0;
        for(int i = n-1; i > ind; i -= m)
        {
            ans += 2*(pos[i] - ctr);
        }

        for(int i = 0; i < ind; i += m)
        {
            ans += 2*(ctr - pos[i]);
        }

        return ans;
    };

    ll l = 0, r = n-1;
    while(r - l > 3)
    {
        ll mid1 = l + (r-l)/3;
        ll mid2 = r - (r-l)/3;

        ll val1 = eval(pos[mid1], mid1);
        ll val2 = eval(pos[mid2], mid2);
        
        if(val1 < val2)
        {
            r = mid2;
        }
        else
        {
            l = mid1;
        }
    }

    ll ans = 1e18;
    for(int i = l; i <= r; i++)
    {
        ans = min(ans, eval(pos[i], i));
    }

    cout << ans << endll;

    return 0;
}
