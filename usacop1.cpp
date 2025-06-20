

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
        vector<int> sufMaxInd(N+1, N-1);
        for(int i = N-1; i >= 0; i--)
        {
            sufMax[i] = max(sufMax[i+1], a[i]);
            if(sufMax[i] == a[i])
            {
                sufMaxInd[i] = i;
            }
            else
            {
                sufMaxInd[i] = sufMaxInd[i+1];
            }
        }

        vector<int> ans{}, ansNoOp{};

        auto eval = [&](int ind)
        {
            //move the farthest suffix max to the front
            //find the farthest suffix max
            int farthest = sufMaxInd[ind];

            vector<int> window{sufMax[ind]}, sufMaxWindow{};
            for(int i = ind; i < farthest; i++)
            {
                window.push_back(a[i]);
            }

            sufMaxWindow = vector<int>(window.size() + 1, sufMax[farthest+1]);
            for(int i = window.size() - 1; i >= 0; i--)
            {
                sufMaxWindow[i] = max(sufMaxWindow[i+1], window[i]); 
            }

            vector<int> windowAns{};

            for(int i = 0; i < window.size(); i++)
            {
                if(window[i] == sufMaxWindow[i])
                {
                    windowAns.push_back(window[i]);
                }
            }

            //dbg(window)
            //dbg(sufMaxWindow)
            //dbg(windowAns)

            return windowAns;
        };
        
        bool found = false;
        for(int i = 0; i < N; i++)
        {
            if(i == 0 || sufMaxInd[i-1] != sufMaxInd[i])
            {
                //try to swap
                vector<int> curEval = eval(i);
                int noOp = sufMax[i];

                vector<int> newAns = ansNoOp;
                newAns.insert(newAns.end(), curEval.begin(), curEval.end());
                
                ansNoOp.push_back(noOp);

                if(lexGreater(newAns, ans))
                {
                    ans = newAns;
                }
                else 
                {
                    ans.push_back(noOp);
                }
            }
        }
        
        if(lexGreater(ansNoOp, ans))
        {
            ans = ansNoOp;
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
