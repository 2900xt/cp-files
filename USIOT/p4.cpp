#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M, Q; cin >> N >> M >> Q;
    vector<vector<int>> grid = vector(N+1, vector<int>(M+1, 0));

    ll ans = 0;
    for(int q = 0; q < Q; q++)
    {
        int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
        for(int i = r1; i <= r2; i++)
        {
            //if cells are different here then 
        }
    }
}