#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops") 
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;

#define endll '\n'

void solve(int num_tc)
{
    srand(time(0));
    int n = 40;
    cout << 40 << endll;
    for(int i = 0; i < n; i++)
    {
        cout << rand() % 25 << " ";
    }
}

int32_t main()
{
    freopen("bunches_data.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    int T = 1;
    //cin >> T;
    for(int t = 0; t < T; t++){
        solve(t+1);
    }
}
