#include <bits/stdc++.h>
#include <string>

using namespace std;
typedef long long ll;
#define endll '\n'

void solve()
{
    int L, N; cin >> L >> N;
    vector<array<int, 4>> stars{};
    map<char, int> starPowers{};
    starPowers['M'] = 3;
    starPowers['K'] = 4;
    starPowers['G'] = 5;
    starPowers['F'] = 6;
    starPowers['A'] = 7;
    starPowers['B'] = 8;
    starPowers['O'] = 9;

    string s;
    getline(cin, s);

    for(int i = 0; i < N; i++)
    {
        getline(cin, s);
        s += ',';

        //split the string by commas
        stringstream ss(s);
        array<int, 4> star{};

        string token;
        getline(ss, token, ',');
        star[0] = starPowers[token[0]];

        for(int i = 0; i < 3; i++)
        {
            getline(ss, token, ',');
            star[i + 1] = stoi(token);
        }

        stars.push_back(star);
    }

    stars.push_back({0, L-1, L-1, L-1});

    //state = (star on, fuel left)
    //value = minimum distance
    //we can't visit any star with a manhattan distance < current star. 
    //sort stars by manhattan distance

    sort(stars.begin(), stars.end() , [](const array<int, 4>& a, const array<int, 4>& b)
    {
        int d1 = abs(a[1]) + abs(a[2]) + abs(a[3]);
        int d2 = abs(b[1]) + abs(b[2]) + abs(b[3]);
        return d1 < d2;
    });

    vector<vector<int>> dp(N+1, vector<int>(21, 100));

    for(int i = 0; i <= N; i++)
    {
        //try to transition from (0, 20) to i
        int dist = abs(stars[i][1]) + abs(stars[i][2]) + abs(stars[i][3]);
        if(dist <= 20)
        {
            int newFuel = min(20, 20 - dist + stars[i][0]);
            dp[i][newFuel] = dist;
        }

        //try to transition from any star j st. j < i to i
        for(int j = 0; j < i; j++)
        {
            int dist = abs(stars[i][1] - stars[j][1]) + abs(stars[i][2] - stars[j][2]) + abs(stars[i][3] - stars[j][3]);
            if(dist > 20) continue;

            for(int fuel = dist; fuel <= 20; fuel++)
            {
                int newFuel = min(20, fuel - dist + stars[i][0]);
                if(dp[j][fuel] + dist < dp[i][newFuel])
                {
                    dp[i][newFuel] = dp[j][fuel] + dist;
                }
            }
        }
    }

    int ans = 1e9;
    for(int fuel = 0; fuel <= 20; fuel++)
    {
        ans = min(ans, dp[N][fuel]);
    }
    
    cout << ans << endll;
}

int main()
{
    int T; cin >> T;
    while(T--)
    {
        solve();
    }
}