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
        int N; cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        bool pos = count(a.begin(), a.end(), 1) != N;

        for(int i = 0; i < N-1; i++)
        {
            if(!a[i] && !a[i+1]) 
            {
                pos = false;
            }
        }

        if(pos) cout << "NO" << endll;
        else cout << "YES" << endll;
    }

    return 0;
}
