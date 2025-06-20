#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endll '\n'

typedef long long ll;

vector<int> parent{}, depths{}, vis{};
vector<vector<int>> children{};

int leaves = 0;

void dfsLeaves(int node, int depth = 0)
{
    if(children[node].empty())
    {
        leaves++;
    }

    depths[node] = depth;

    for(int child : children[node])
    {
        dfsLeaves(child, depth + 1);
    }
}

int dfsTilFound(int node)
{
    if(vis[node]) return depths[node]+1;
    vis[node] = 1;

    if(node == 0) return 0;
    
    int par = parent[node];
    return dfsTilFound(par);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    parent.resize(N+1);
    children.resize(N+1);
    depths.resize(N+1);
    vis.resize(N+1);
    parent[0] = 0;
    for(int i = 1; i <= N; i++)
    {
        cin >> parent[i];
        children[parent[i]].push_back(i);
        //cerr << parent[i] << " " << i << endll;   
    }

    dfsLeaves(0);

    vector<int> queries{}, ans{};
    for(int i = 0; i < leaves; i++)
    {
        int x; cin >> x;
        queries.push_back(x);
    }

    for(int i = leaves - 1; i >= 0; i--)
    {
        int x = queries[i];
        ans.push_back(dfsTilFound(x));
    }

    reverse(ans.begin(), ans.end());
    for(int i : ans)
    {
        cout << i << endll;
    }
}