#include<bits/stdc++.h>

using namespace std;

vector<int> kahn(int n, vector<int> adj[])
{
    vector<int> indegree(n+1,0);
    for(int i = 1; i <= n; i++)
    {
        for(auto &it : adj[i])
        {
            indegree[it]++;
        }
    }

    queue<int> q;

    vector<int> ans;

    for(int i = 1; i <= n; i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }


    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        ans.push_back(node);

        for(auto &it : adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0)q.push(it);
        }
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
    }
    vector<int> ans = kahn(n,adj);

    for(auto &it : ans)
    {
        cout<<it<<" ";
    }

    return 0;
}