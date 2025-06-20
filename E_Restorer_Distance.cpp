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
    
    int N, A, R, M; cin >> N >> A >> R >> M;
    vector<ll> h(N);

    M = min(M, A+R);
    
    for(int i = 0; i < N; i++)
    {
        cin >> h[i];
    }

    sort(h.begin(), h.end());

    auto eval = [&](ll midHeight)
    {
        ll numToAdd = 0, numToRemove = 0;
        for(int i = 0; i < N; i++)
        {
            if(h[i] > midHeight) numToRemove += h[i] - midHeight;
            else numToAdd += midHeight - h[i];
        }

        ll cost = 0;
        ll both = min(numToAdd, numToRemove);
        cost += both * M;
        numToAdd -= both, numToRemove -= both;

        cost += numToAdd * A;
        cost += numToRemove * R;
        return cost;
    };

    ll r = 2e9, l = 0;
    while(r - l > 3)
    {
        ll midL = l + (r-l)/3;
        ll midR = r - (r-l)/3;

        ll valL = eval(midL), valR = eval(midR);

        if(valL > valR)
        {
            l = midL;
        }
        else 
        {
            r = midR;
        }
    }

    ll ans = 1e18;
    for(int i = l; i <= r; i++) 
    {
        ans = min(ans, eval(i));
    }

    cout << ans << endll;

    return 0;
}
