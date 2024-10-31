#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int node, vector<int> adj[], stack<int> &topo, vector<int> &vis)
{
    vis[node] = 1;

    for (auto &it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, adj, topo, vis);
        }
    }

    topo.push(node);
}

void dfs2(int node, vector<int> adj[], vector<int> &vis, vector<int> &col, int c)
{
    vis[node] = 1;
    col[node] = c;

    for (auto &it : adj[node])
    {
        if (vis[it] == 0)
        {
            dfs2(it, adj, vis, col, c);
        }
    }
}

int dfs3(int node, vector<int> adj[], vector<int> &dp, vector<int> &colcoin)
{
    if (dp[node] != -1)
        return dp[node];
    dp[node] = 0;
    int ans = colcoin[node];
    for (auto &it : adj[node])
    {
        ans = max(ans, colcoin[node] + dfs3(it, adj, dp, colcoin));
    }

    return dp[node] = ans;
}

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> adj[n + 1];
    vector<int> adjR[n + 1];
    vector<int> adjC[n + 1];

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adjR[v].push_back(u);
    }

    stack<int> topo;
    vector<int> vis(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
            dfs(i, adj, topo, vis);
    }

    vector<int> col(n + 1, 0);
    vector<int> colcoin(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        vis[i] = 0;
    }

    int c = 0;

    while (!topo.empty())
    {
        int node = topo.top();
        topo.pop();
        if (!vis[node])
        {
            c++;
            dfs2(node, adjR, vis, col, c);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        colcoin[col[i]] += arr[i - 1];
        for (auto &j : adj[i])
        {
            if (col[i] != col[j])
            {
                adjC[col[i]].push_back(col[j]);
            }
        }
    }

    vector<int> dp(n + 1, -1);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dfs3(i, adjC, dp, colcoin));
    }

    cout << ans << endl;

    return 0;
}