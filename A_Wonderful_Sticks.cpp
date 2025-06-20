#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

    
inline void open(string name){
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}    

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        int n; cin >> n;
        string s; cin >> s;
        int lo = 0, hi = 0;
        vector<int> arr(n);
        arr[0] = 0;
        for(int i = 1; i < n; i++)
        {
            if(s[i-1] == '<')
            {
                arr[i] = --lo;
            }
            else 
            {
                arr[i] = ++hi;
            }
        }
        
        for(int i = 0; i < n; i++)
        {
            cout << arr[i] - lo + 1 << " ";
        }
        cout << endll;
    }
    return 0;
}
