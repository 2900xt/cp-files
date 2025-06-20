#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

    
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

void solve()
{
    int N; cin >> N;

    cout << "mul " << 999999999 << endl;
    ll res; cin >> res;
    assert(res == 1);

    cout << "digit" << endl;
    cin >> res;
    assert(res == 1);

    if(N != 81)
    {
        cout << "add " << N-81 << endl;
        cin >> res;
        assert(res == 1);
    }

    cout << "!" << endl;
    cin >> res;
    assert(res == 1);
}

int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0); cout.tie(0);
    
    int T; cin >> T; 

    while(T--)
    {
        solve();
    }

    return 0;
}
