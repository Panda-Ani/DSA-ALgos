/*
    Disclaimer: Rooted at 1
    1) Find initial parents and level through dfs
    2) Populate 2's parents
    3) LCA
        3.1) Make them to same level finding Kth Parent
        3.2) Find the point they stop being equal
        3.3) Return the found point + 1 node

*/
#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int par, vector<int> adj[], vector<int> &vis, vector<int> &level, vector<vector<int> > &parent, int lvl)
{
    vis[node] = 1;
    parent[0][node] = par;
    level[node] = lvl;
    for(auto &it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,node,adj,vis,level,parent,lvl+1);
        }
    }
}

int KthParent(int node, int k, vector<vector<int> > &parent, int maxPower)
{
    for(int i = 0; i < maxPower; i++)
    {
        if(k&(1<<i))
        {
            node = parent[i][node];
            if(node == -1)return node;
        }
    }
    return node;
}

int LCA(int u, int v, vector<vector<int> > &parent, int maxPower, vector<int> &level)
{
    // step - 3.1
    if(level[u]>=level[v])
    {
        u = KthParent(u,level[u]-level[v],parent,maxPower);
    }
    else
    {
        v = KthParent(v,level[v]-level[u],parent,maxPower);
    }

    if(u==v)return u;

    // step - 3.2
    for(int i = maxPower - 1; i >= 0; i--)
    {
        if(parent[i][u] != parent[i][v])
        {
            u = parent[i][u];
            v = parent[i][v];
        }
    }

    // step - 3.3
    return parent[0][u];
}

void Binary_Lifting(int n, int u,int v, vector<int> adj[])
{
    // step - 1
    vector<int> level(n,0);
    int maxPower = log2(n) + 5;
    vector<vector<int> > parent(maxPower, vector<int> (n,0));
    vector<int> vis(n,0);
    dfs(1,-1,adj,vis,level,parent,0); // Signifies rooted at 1

    // step - 2
    for(int i = 1; i < maxPower; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int intermediate = parent[i-1][j];
            if(intermediate != -1)
            {
                parent[i][j] = parent[i-1][intermediate];
            }
        }
    }

    //step - 3
    cout<<LCA(u,v,parent,maxPower,level)<<endl;
    
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int from_node, to_node;
    cin>>from_node>>to_node;
    Binary_Lifting(n+1,from_node,to_node,adj);

    return 0;
}