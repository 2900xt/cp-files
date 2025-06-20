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
    vector<int> bits(N);
    map<int, int> msbs{};
    for(int i = 0; i < N; i++)
    {
        cout << "? " << i+1 << " " << i+1 << endl;
        int x; cin >> x;
        bits[i] = x;
        msbs[x] = i;
    }

    vector<int> ans(N);
    for(int i = 0; i < N; i++)
    {
        ans[i] |= (1 << bits[i]);
        for(int bit = bits[i] - 1; bit >= 0; bit--)
        {
            cout << "? " << i+1 <<  " " << msbs[bit]+1 << endl; 
            int x; cin >> x;

            if(x == bit)
            {
                ans[i] |= (1 << bit);
            }
        }
    }

    cout << "! ";
    for(int i = 0; i < N; i++)
    {
        cout << ans[i] << " "; 
    }
    cout << endl;
}

int main()
{
    ll T = 1;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
