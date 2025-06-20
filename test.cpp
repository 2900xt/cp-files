

#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'

typedef long long ll;


int main()
{
    srand(time(0));
    int n = rand() % (int)1e6;
    map<ll, ll> ctr{};
    for(int i = 0; i < n; i++)
    {
        ll val = i;
        string s = to_string(val);
        ctr[s.front() - '0']++;
    }

    for(int i = 1; i < 9; i++)
    {
        cout << i << ": " << ctr[i] << endll;
    }
    cout << 0 << ": " << ctr[0] << endll;

}
