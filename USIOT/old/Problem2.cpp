#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void solve(int num_tc)
{
    int N, M, L, K;
    cin >> N >> M >> L >> K;

    if(K == 0)
    {
        cout << "YES" << endll;
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < M; j++)
            {
                cout << 'B';
            }
            cout << endll;
        }
        return;
    }

    if((N-L+1)*(M-L+1) < K)
    {
        cout << "NO" << endll;
        return;
    }

    if(L % 3 != 0)
    {
        cout << "NO" << endll;
        return;
    }

    

    cout << "YES" << endll;

    vector<string> ans(N, string(M, ' '));
    vector<char> ch = {'R', 'G', 'B'};
    for(int i = 0; i < L - 1; i++)
    {
        for(int j = 0; j < M; j++)
        {
            ans[i][j] = ch[i%3];
        }
    }

    int cnt = 0;
    char endChar = 'G';
    for(int i = L - 1; i < N; i++)
    {
        for(int j = 0; j < L - 1; j++)
        {
            if(cnt <= K) 
            {
                ans[i][j] = ch[i%3];
            }
            else 
            {
                ans[i][j] = endChar;
            }
        }

        for(int j = L - 1; j < M; j++)
        {
            if(cnt < K) 
            {
                ans[i][j] = ch[i%3];
                cnt++;

                if(cnt == K)
                {
                    endChar = (ch[i%3] == 'B' ? 'G' : 'B');
                }
            }
            else 
            {
                ans[i][j] = endChar;
            }
        }
    }

    for(string s : ans)
    {
        cout << s << endll;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    //cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
