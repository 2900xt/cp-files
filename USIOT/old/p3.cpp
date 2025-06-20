#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void solve(int num_tc)
{
    int N; cin >> N;
    vector<ll> arr(N + 2);
    for(int i = 0; i < N + 2; i++)
    {
        cin >> arr[i];
    }

    if(N == 2)
    {
        if(min(arr[2], arr[1]) + max(arr[2], arr[1])/2 >= 0)
        {
            cout << "YES" << endll;
            return;
        }
    }

    if(N == 3)
    {
        
    }

    for(int i = 1; i <= N; i++)
    {
        if(arr[i] < 0)
        {
            cout << "NO" << endll;
            return;
        }
    }

    cout << "YES" << endll;
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
