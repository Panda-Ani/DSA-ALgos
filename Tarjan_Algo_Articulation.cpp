#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int par, vector<int> &vis, vector<int> adj[], vector<int> &tin,
        vector<int> &low, vector<int> &mark, int &timer)
    {
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        int child = 0;
        for(auto &it : adj[node])
        {
            if(it == par)continue;
            if(!vis[it])
            {
                dfs(it,node,vis,adj,tin,low,mark,timer);
                low[node] = min(low[node],low[it]); // check for lowest time in adj
                if(low[it] >= tin[node] && par != -1) // it can't be reached by node
                {
                    mark[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node],tin[it]);
            }
        }

        if(child > 1 && par == -1)
        {
            mark[node] = 1;
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

    vector<int> mark(n+1,0);

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
        {
            dfs(i,-1,vis,adj,tin,low,mark,timer);
        }
    }

    vector<int> ans;

    for(int i = 0; i <= n; i++)
    {
        if(mark[i])ans.push_back(i);
    }

    for(auto &it : ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;

    return 0;
}