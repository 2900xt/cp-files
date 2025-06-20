#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'

typedef long long ll;


int main()
{
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int n; cin >> n;
        cout << 2*n - 1 << endll;
        for(int i = 0; i < n; i++)
        {
            cout << i+1 << " " << 1 << " " << i+1 << endll;
            if(i+2 <= n) cout << i+1 << " " << i+2 << " " << n << endll;
        }
    }
}
