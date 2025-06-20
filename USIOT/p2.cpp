#include <string>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> arr(N), rev(M+1);
    for(int i = 0; i < N; i++)
    {
        int k; cin >> k;
        for(int j = 0; j < k; j++) 
        {
            int x; cin >> x;
            arr[i].push_back(x);
            rev[x].push_back(i);
        }
    }

    vector<pair<int, int>> out;

    set<int> allSubjects{};
    for(int i = 0; i < M; i++)
    {
        allSubjects.insert(i+1);
    }

    for(int i = 1; i <= M; i++)
    {
        allSubjects.erase(i);
        set<int> ans = allSubjects;
        for(int student : rev[i])
        {
            for(int subject : arr[student]) ans.erase(subject);
        }

        for(int j : ans)
        {
            out.push_back({i, j});
        }
    }

    cout << out.size() << endll;

    for(auto [x, y] : out)
    {
        cout << x << " " << y << endll;
    }
}