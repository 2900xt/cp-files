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
        int n, k; cin >> n >> k;
        for(int i = 0; i < k; i++)
        {
            cout << 1;
        }
        for(int i = k; i < n; i++)
        {
            cout << 0;
        }
        cout << endll;
    }
}
