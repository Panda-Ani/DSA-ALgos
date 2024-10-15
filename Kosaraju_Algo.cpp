#include <bits/stdc++.h>

using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[node] = 1;
    for(auto &it : adj[node])
    {
        if(!vis[it])
        {
            dfs(it,adj,vis,st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adjR[])
{
    vis[node] = 1;

    for(auto &it : adjR[node])
    {
        if(!vis[it])
        {
            dfs2(it,vis,adjR);
        }
    }
}

int kosaraju(int n, vector<int> adj[], vector<int> adjR[])
{
    vector<int> vis(n+1,0);
    stack<int> st;

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i,adj,vis,st);
        }
    }

    for(int i = 1; i <= n; i++)vis[i] = 0;
    int scc = 0;
    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!vis[node])
        {
            dfs2(node,vis,adjR);
            scc++;
        }
    }

    return scc;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> adj[n + 1];
    vector<int> adjR[n + 1];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adjR[v].push_back(u);
    }
    cout<<kosaraju(n, adj, adjR)<<'\n';

    return 0;
}