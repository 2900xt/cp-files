#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << __LINE__ << ": " << #x << "=" << x << endll;

void dijkstra(vector<ll>& distance, vector<unordered_set<ll>> &adj, ll x, ll n)
{
	vector<bool> processed(n);
	priority_queue<pair<ll, ll>> q{};
	
	for (ll i = 0; i < n; i++) distance[i] = 1e9;
	distance[x] = 0;
	q.push({0,x});
	
	while (!q.empty()) 
	{
		ll a = q.top().second; q.pop();
		if (processed[a]) continue;
		processed[a] = true;
		
		for (auto u : adj[a]) 
		{
			ll b = u, w = 1;
			if (distance[a] + w < distance[b]) 
			{
				distance[b] = distance[a] + w;
				q.push({-distance[b], b});
			}
		}
	}
}

void solve(ll num_tc)
{
    ll N, M; cin >> N >> M;
    vector<unordered_set<ll>> normalAdj(N);
    vector<ll> distance0(N), distanceN(N);

    vector<pair<ll, ll>> edges;

    for(ll i = 0; i < M; i++)
    {
        ll u, v; cin >> u >> v;

        normalAdj[u].insert(v);
        normalAdj[v].insert(u);
        edges.push_back({u, v});
    }

    dijkstra(distance0, normalAdj, 0, N);
    dijkstra(distanceN, normalAdj, N - 1, N);
    
    int ans = 0;
    for(ll i = 0; i < N; i++)
    {
        for(ll j = i+1; j < N; j++)
        {
            if(distance0[N - 1] <= min(distance0[i] + distanceN[j] + 1, distance0[j] + distanceN[i] + 1))
            {
                ans++;
            }
        }
    }

    for(auto e : edges)
    {
        int i = e.first, j = e.second;
        if(distance0[N - 1] <= min(distance0[i] + distanceN[j] + 1, distance0[j] + distanceN[i] + 1))
        {
            ans--;
        }
    }



    cout << ans << endll;
}

int main()
{
    ll T = 1;
    for(ll t = 0; t < T; t++){
        solve(t+1);
    }
}
