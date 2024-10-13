#include<bits/stdc++.h>

using namespace std;

void topoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[])
{
    vis[node] = 1;

    for(auto &it : adj[node])
    {
        if(!vis[it])
        {
            topoSort(it,vis,st,adj);
        }
    }

    st.push(node);
}

vector<int> topo(int n, vector<int> adj[])
{
    vector<int> vis(n+1,0);
    stack<int> s;

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            topoSort(i,vis,s,adj);
        }
    }
    vector<int> ans;

    while(!s.empty())
    {
        int node = s.top();
        s.pop();

        ans.push_back(node);
    }

    return ans;
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
    
    vector<int> ans = topo(n,adj);

    for(auto &it : ans)
    {
        cout<<it<<" ";
    }

    return 0;
}