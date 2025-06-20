#include <string>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;
    vector<int> ans(10);
    for(int i = 1; i <= N; i++)
    {
        string val = to_string(i);
        for(char c : val)
            ans[c - '0']++;
    }

    for(int i = 0; i < 10; i++)
        cout << ans[i] << " ";
}