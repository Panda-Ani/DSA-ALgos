#include<bits/stdc++.h>

using namespace std;

void dfs(int node, int par, vector<int> tree[], vector<int> &intime, vector<int> &outtime, int &time)
{
    intime[node] = ++time;

    for(auto &it : tree[node])
    {
        if(it != par)
        {
            dfs(it,node,tree,intime,outtime,time);
        }
    }

    outtime[node] = ++time;
}

int main()
{
    int n;
    cin>>n;
    vector<int> tree[n+1];

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < n - 1; i++)
    {
        int u,v;
        cin>>u>>v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    vector<int> intime(n+1,0);
    vector<int> outtime(n+1,0);
    int time = 0;
    dfs(1,-1,tree,intime,outtime,time);

    vector<int> euler(2*n+1,0);

    for(int i = 1; i <= n; i++)
    {
        euler[intime[i]] = euler[outtime[i]] = arr[i-1];
    }
    
    for(auto &it : euler)
    {
        cout<<it<<" ";
    }

    cout<<endl;
}