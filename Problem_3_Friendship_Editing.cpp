#include <bits/stdc++.h>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N, M;
    cin >> N >> M;
    // Use 0-indexing.
    vector<vector<int>> orig(N, vector<int>(N,0));
    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        orig[a][b] = 1;
        orig[b][a] = 1;
    }
    
    // The candidate valid graph is determined by a subset U ⊆ {0,1,...,N-1}.
    // For each pair (i, j) with i<j, we force:
    //   F(i,j) = 1 if (i in U or j in U), and F(i,j) = 0 otherwise.
    // The cost for the candidate is the number of pairs (i,j) where F(i,j) ≠ orig(i,j).
    
    int best = INT_MAX;
    // There are 2^N possible subsets.
    for (int mask = 0; mask < (1 << N); mask++){
        int cost = 0;
        for (int i = 0; i < N; i++){
            for (int j = i+1; j < N; j++){
                // If either i or j is in U then the edge should be present.
                int desired = (((mask >> i) & 1) || ((mask >> j) & 1)) ? 1 : 0;
                if (orig[i][j] != desired) cost++;
            }
        }
        best = min(best, cost);
    }
    
    cout << best << "\n";
    return 0;
}
