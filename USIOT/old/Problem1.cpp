#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void solve(int num_tc)
{
    string s; cin >> s;
    set<string> alphabet{};
    vector<string> ans{};

    for(int i = 0; i < s.length(); i++)
    {
        if(i != s.length() - 1 && s[i] == s[i+1])
        {
            string ins = s[i] + string() + s[i+1];
            if(alphabet.count(ins))
            {
                cout << -1 << endll;
                return;
            }

            i++;
            alphabet.insert(ins);
            ans.push_back(ins);
        }
        else 
        {
            string ins = s[i] + string();
            if(alphabet.count(ins))
            {
                cout << -1 << endll;
                return;
            }

            alphabet.insert(ins);
            ans.push_back(ins);
        }
    }

    for(string s : ans) cout << s << " ";
    cout << endll;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  

    ll T = 1;
    cin >> T;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
