#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    freopen("input.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int> residues(2025);

    int n = 1e7;
    for(int i = 0; i < n; i++)
    {
        int x; cin >> x;
        residues[x % 2025]++;
    }

    sort(residues.rbegin(), residues.rend());

    cout << residues[0] + residues[1] + residues[2] << endll;
}
