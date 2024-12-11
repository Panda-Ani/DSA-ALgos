#include<bits/stdc++.h>

using namespace std;

    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &isvis)
    {
        vis[node] = 1;
        isvis[node] = 1;
        for(auto &it : adj[node])
        {
            if(vis[it])
            {
                if(isvis[it])return true;
            }
            else
            {
                if(dfs(it,adj,vis,isvis))return true;
            }
        }
        isvis[node] = 0;
        return false;
    }
    
    bool isCyclic(int n, vector<vector<int>> adj) {
        vector<int> vis(n,0);
        vector<int> isvis(n,0);
        
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                if(dfs(i,adj,vis,isvis))return true;
            }
        }
        
        return false;
    }

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int> > edges;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        edges.push_back({u,v});
    }

    vector<vector<int> > adj(n);

    for(auto &edge : edges)
    {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }

    cout<<isCyclic(n,adj)<<endl;
}