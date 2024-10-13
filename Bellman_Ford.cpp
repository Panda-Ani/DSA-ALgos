#include<bits/stdc++.h>

using namespace std;

vector<int> bellman_ford(int src, int n, vector<vector<int> > &edges)
{
    vector<int> dist(n+1,1e8);
    dist[src] = 0;

    for(int i = 0; i < n - 1; i++)
    {
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if(dist[u] != 1e8 && dist[v] > dist[u] + wt)
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist;
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > edges;
    for(int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    }
    
    vector<int> dist = bellman_ford(1,n,edges);

    for(auto &it : dist)
    {
        cout<<it<<" ";
    }
    cout<<'\n';

    return 0;
}