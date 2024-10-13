#include <bits/stdc++.h>

using namespace std;

int prim(int n, vector<pair<int,int> > adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    vector<int> vis(n + 1, 0);

    pq.push({0, 1});

    int sum = 0;

    while (!pq.empty())
    {
        int node = pq.top().second;
        int wt = pq.top().first;
        pq.pop();

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wt;

        for (auto &it : adj[node])
        {
            int adjNode = it.first;
            int weight = it.second;
            if (!vis[adjNode])
            {
                pq.push({weight, adjNode});
            }
        }
    }

    return sum;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int,int> > adj[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v,wt});
        adj[v].push_back({u,wt});
    }
    int ans = prim(n, adj);

    cout << ans << endl;

    return 0;
}