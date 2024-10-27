#include<bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int> &vis, int col, vector<int> &color, vector<int> adj[])
{
    vis[node] = 1;
    color[node] = col;

    for(auto &it : adj[node])
    {
        if(color[node] == color[it])return false;
        if(!vis[it])
        {
            if(dfs(it,vis,!col,color,adj) == false)return false;
        }
    }

    return true;
}

bool bipartite(int n, vector<int> adj[], vector<int> &color)
{
    vector<int> vis(n+1,0);
    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            if(dfs(i,vis,0,color,adj) == false)
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int> adj[n+1];

    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> color(n+1,-1);

    if(!bipartite(n,adj,color))
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            cout<<color[i]+1<<" ";
        }
        cout<<endl;
    }
}