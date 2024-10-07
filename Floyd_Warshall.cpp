#include<bits/stdc++.h>

using namespace std;

void floyd_warshall(int n, vector<vector<int> > &dis)
{
    for(int k = 0; k < n; k++)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int> > edges;
    vector<vector<int> > dis(n+1, vector<int> (n+1,1e9));

    for(int i = 0; i < m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }

    for(auto &it : edges)
    {
        dis[it[0]][it[1]] = it[2];
        dis[it[1]][it[0]] = it[2];
    }
    // cout<<"YES";

    for(int i = 0; i <= n; i++)for(int j = 0; j <= n; j++)if(i==j)dis[i][j] = 0;

    floyd_warshall(n+1,dis);

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}