#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'
typedef long long ll;

void solve()
{
    ll A, B, C, D;
    cin >> A >> B >> C >> D;
    
    ll ans = 0;
    while(true)
    {
        //cerr << C << " - " << D << endll;
        // found answer type shi
        if(C == A && D == B) 
        {
            cout << ans << endll;
            return;
        }

        //we drop below initial, ggs go next
        //numbers can't be equal cuz 0 is cooked
        if(C < A || D < B || C == D) 
        {
            cout << -1 << endll;
            return;
        }
        
        if(D > C) 
        {
            // subtract some multiples of c from d
            // we can speed up by subtracting the amount of times we can subtract til d <= b
            ll numToDo = (D - B) / C;
            if(numToDo < 1) 
            {
                //tle oops
                numToDo = 1;
            }
            //cerr << k << endll;
            D -= numToDo * C;
            ans += numToDo;
            
        } 
        else 
        { 
            // opposite - subtract some multiples of d from c
            // we can speed up by subtracting the amount of times we can subtract til a <= c
            ll numToDo = (C - A) / D;
            if(numToDo < 1) 
            {
                numToDo = 1;
            }
            C -= numToDo * D;
            ans += numToDo; 
            //cerr << k << ", " << ops << endll;
        }
    }

    cerr << "wtf" << endll;
    cout << -1 << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    for(int t = 0; t < T; t++)
    {
        solve();
    }
}

//pray to god this passes 