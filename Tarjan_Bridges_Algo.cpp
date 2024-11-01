#include<bits/stdc++.h>

using namespace std;

// tin: time of insertion of node
// low: lowest time of insertion among all adjacent except for parent

void dfs(int node, int par, vector<int> &vis, vector<int> adj[], vector<int> &tin,
        vector<int> &low, vector<vector<int> > &bridges, int &timer)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;

        for(auto &it : adj[node])
        {
            if(it == par)continue;
            if(!vis[it])
            {
                dfs(it,node,vis,adj,tin,low,bridges,timer);
                low[node] = min(low[node],low[it]); // check for lowest time in adj
                if(low[it] > tin[node]) // it can't be reached by node
                {
                    bridges.push_back({node,it});
                }
            }
            else
            {
                low[node] = min(low[node],low[it]);
            }
        }
    }

int main()
{
    int n, m;
    cin>>n>>m;
    vector<vector<int> > edges;

    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    vector<int> adj[n+1];

    for(auto &it : edges)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> tin(n+1,0), low(n+1,0), vis(n+1,0);

    int timer = 1;

    vector<vector<int> > bridges;

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,adj,tin,low,bridges,timer);
        }
    }

    for(auto &it : bridges)
    {
        cout<<it[0]<<" "<<it[1]<<endl;
    }

    return 0;
}
