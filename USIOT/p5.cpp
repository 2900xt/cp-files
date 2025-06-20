#include <queue>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define endll '\n'

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    ll N, M, Q; cin >> N >> M >> Q;
    vector<ll> a(N), b(N);
    for(int i = 0; i < N; i++) 
    {
        cin >> a[i] >> b[i];
    }

    vector<ll> dist((1 << N), 1e18);
    priority_queue<pair<ll, ll>> pq;

    for(int i = 0; i < M; i++)
    {
        int k; cin >> k;
        ll mask = 0;
        for(int j = 0; j < k; j++)
        {
            int x; cin >> x;
            mask |= (1 << x);
        }

        dist[mask] = 0;
        pq.push({0, mask});
    }

    while(!pq.empty())
    {
        ll d = -pq.top().first;
        ll mask = pq.top().second;
        pq.pop();

        if(d > dist[mask]) continue;

        for(int i = 0; i < N; i++)
        {
            if(mask & (1 << i)) 
            {
                ll newMask = mask & ~(1 << i);
                if(dist[newMask] > dist[mask] + b[i]) 
                {
                    dist[newMask] = dist[mask] + b[i];
                    pq.push({-dist[newMask], newMask});
                }
            }
            else 
            {
                ll newMask = mask | (1 << i);
                if(dist[newMask] > dist[mask] + a[i]) 
                {
                    dist[newMask] = dist[mask] + a[i];
                    pq.push({-dist[newMask], newMask});
                }
            }
        }
    }


    
    for(int i = 0; i < Q; i++)
    {
        int k; cin >> k;
        ll mask = 0;
        for(int j = 0; j < k; j++)
        {
            int x; cin >> x;
            mask |= (1 << (x));
        }

        cout << dist[mask] << endll;
    }
}