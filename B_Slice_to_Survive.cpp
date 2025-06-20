#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

    
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

ll cielLog2(ll x)
{
    if(x == 1) return 0;

    return 1 + cielLog2((x+1)/2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
       // cerr << "T: " << t << endll;
        ll N, M, A, B; cin >> N >> M >> A >> B;
        ll ans = 1e18;

        vector<pair<int, int>> conditions 
        {
            {A, M}, {N, B}, {N-A+1, M}, {N, M-B+1}
        };

        for(auto [n, m] : conditions)
        {
            //cerr << n << ", " << m << endll;
            ans = min(ans, 1 + cielLog2(n) + cielLog2(m));
        }

        cout << ans << endll;
    }

    return 0;
}
