#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    freopen("input.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    srand(time(0));

    ll n = 1e7;
    for(int i = 0; i < n; i++)
    {
        cout << rand() % (ll)(1e9) << " ";
    }

    cout << endll;
}
