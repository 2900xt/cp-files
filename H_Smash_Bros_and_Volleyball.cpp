#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> fun(n);
    for (int i = 0; i < n; i++){
        cin >> fun[i];
    }
    
    long long maxJoy = -1e18;
    
    // x is the starting room index (0-indexed)
    for (int x = 0; x <= n - a; x++){
        long long forcedSum = 0;
        for (int i = 0; i < a; i++){
            forcedSum += fun[x + i];
        }
        
        long long bestOptional = 0, currentOptional = 0;
        long long candidate = forcedSum;  // if we add 0 extra activities
        // We can add up to b optional activities, but do not exceed array bounds.
        int extraActivities = min(b, n - (x + a));
        for (int k = 0; k < extraActivities; k++){
            currentOptional += fun[x + a + k];
            bestOptional = max(bestOptional, currentOptional);
            candidate = max(candidate, forcedSum + bestOptional);
        }
        maxJoy = max(maxJoy, candidate);
    }
    
    cout << maxJoy << "\n";
    return 0;
}
