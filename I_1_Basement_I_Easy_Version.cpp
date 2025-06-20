#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    // Build an adjacency list (1-indexed)
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i <= n - 1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int overallMax = 0;
    
    // For every node, perform BFS to compute distances to all other nodes.
    for (int start = 1; start <= n; start++){
        vector<int> dist(n + 1, -1);
        queue<int> q;
        
        // Initialize BFS from node 'start'
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()){
            int curr = q.front();
            q.pop();
            for (int neighbor : adj[curr]){
                if (dist[neighbor] == -1){
                    dist[neighbor] = dist[curr] + 1;
                    q.push(neighbor);
                }
            }
        }
        
        // Update the overall maximum distance found from node 'start'
        for (int i = 1; i <= n; i++){
            overallMax = max(overallMax, dist[i]);
        }
    }
    
    cout << overallMax << "\n";
    return 0;
}
