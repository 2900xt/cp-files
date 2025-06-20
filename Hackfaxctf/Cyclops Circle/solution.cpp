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
    int N = 1e6, K = 2025;
    indexed_set iset{};
    for(int i = 1; i <= N; i++)
        iset.insert(i);
    
    int prevIndex = 0;
    
    int ans = 0;
    while(!iset.empty())
    {
        int idx = (K + prevIndex) % iset.size();
        if(iset.size() <= 2025)
        {
            ans ^= *iset.find_by_order(idx);
        }
        iset.erase(iset.find_by_order(idx));
        prevIndex = idx;
    }

    cout << ans << endll;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    int T = 1;
    //cin >> T;
    for(int t = 0; t < T; t++){
        solve(t+1);
    }
}
