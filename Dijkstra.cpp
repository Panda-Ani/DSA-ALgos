#include<bits/stdc++.h>

using namespace std;

vector <int> dijkstra(int V, vector<vector<int> > adj[], int source)
    {
        priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
        int n = V;
        int inf = 1e9+10;
        vector<int> dis(n+1,inf);
        dis[source] = 0;
        pq.push({0,source});
        
        while(!pq.empty())
        {
            int node = pq.top().second;
            int dist = pq.top().first;
            pq.pop();
            
            if(dist > dis[node])continue;
            
            for(auto &it : adj[node])
            {
                int wt = it[1] + dist;
                int nxt = it[0];
                if(wt < dis[nxt])
                {
                    dis[nxt] = wt;
                    pq.push({dis[nxt],nxt});
                }
            }
        }
        
        return dis;
    }

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int> > adj[n+1];
    vector<vector<int> > edges;

    for(int i = 0; i < m; i++)
    {
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({u,v,wt});
    } 

    for(auto &edge : edges)
    {
        adj[edge[0]].push_back({edge[1],edge[2]});
        adj[edge[1]].push_back({edge[0],edge[2]});
    }

    int source = 1;

    vector<int> dis = dijkstra(n,adj,source);

    for(auto it : dis)
    {
        cout<<it<<" ";
    }


}