#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

#define rall(x) (x).rbegin(), (x).rend()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void solve(ll num_tc)
{
    ll N, M; cin >> N >> M;
    vector<pair<ll, ll>> data(N);

    for(auto &i : data)
    {
        cin >> i.first >> i.second;
    }

    sort(rall(data));
    ll t = 1, ans = 0;
    while (t <= M && !data.empty())
    {
        t += data.back().first;
        data.pop_back();
        ans += 2;
    }

    cout << ans << endll;
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
