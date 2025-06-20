#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'

typedef long long ll;


//comment to enable debugging


bool lexGreater(const vector<int>& a, const vector<int>& b) 
{
    int n = min(a.size(), b.size());
    for (int i = 0; i < n; i++){
        if(a[i] != b[i])
            return a[i] > b[i];
    }
    return a.size() > b.size();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; cin >> T;
    for(int t = 0; t < T; t++)
    {
        //dbg(t)
        int N; cin >> N;
        vector<int> a(N);
        for(int i = 0; i < N; i++) cin >> a[i];

        vector<int> sufMax(N+1, 0);
        for(int i = N-1; i >= 0; i--)
        {
            sufMax[i] = max(sufMax[i+1], a[i]);
        }

        vector<int> ans{}, cur{};
        for(int i = 0; i < N; i++)
        {
            //ok so try to do a greedy where we pick the number only if its the suffix max
            //if next number is not the suffix maximum, then we swap it

            if(a[i] == sufMax[i])
            {
                ans.push_back(a[i]);
            }
        }

        auto eval = [&](int ind)
        {
            vector<int> curAns{};

            for(int i = 0; i < ind; i++) if(a[i] == sufMax[i])
            {
                curAns.push_back(a[i]);
            }

            vector<int> curSufMax(N+1);
            vector<int> arr = a;
            //move the farthest suffix max to the front
            //find the farthest suffix max
            int farthest = ind;
            for(int j = ind+1; j < N; j++)
            {
                if(sufMax[ind] == arr[j])
                {
                    farthest = j;
                }
            }

            //dbg(i)
            //dbg(farthest) dbg(sufMax[i]) 
            arr.erase(arr.begin() + farthest);
            arr.insert(arr.begin() + ind, sufMax[ind]);
            // dbg(arr)
            //recalculate suffix max
            for(int j = N - 1; j >= 0; j--)
            {
                curSufMax[j] = max(curSufMax[j+1], arr[j]);
            }
            for(int j = ind; j < N; j++)
            {
                //ok so try to do a greedy where we pick the number only if its the suffix max
                //if next number is not the suffix maximum, then we swap it
    
                if(arr[j] == curSufMax[j])
                {
                    curAns.push_back(arr[j]);
                }
            }

            return curAns;
        };

        //dbg(t)

        for(int i = 0; i < N; i++)
        {
            if(i == 0 || sufMax[i-1] != sufMax[i])
            {   
                //try to swap
                vector<int> curEval = eval(i);
                //dbg(curEval)
                if(lexGreater(curEval, ans))
                {
                    ans = curEval;
                }
            }
        }

        for(int i = 0; i < ans.size(); i++)
        {
            cout << ans[i];
            if(i != ans.size() - 1)
            {
                cout << " ";
            }
        }
        cout << endll;
    }
}