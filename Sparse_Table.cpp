#include<bits/stdc++.h>

using namespace std;

#define int long long

vector<int> logTable;

int N;

int merge(int x, int y)
{
    return (x+y);
}

void build(vector<vector<int> > &sparse, vector<int> &arr)
{
    int Log = log2(N);
    for(int i = 0; i < N; i++)sparse[0][i] = arr[i];

    for(int i = 1; i <= Log; i++)
    {
        for(int j = 0; j + (1<<i) <= N; j++)
        {
            sparse[i][j] = merge(sparse[i-1][j],sparse[i-1][j + (1 << (i-1))]);
        }
    }
}

int queryIdp(int l, int r, vector<vector<int> > &sparse)
{
    // Used for Idempotent queries: min, max, gcd O(1)
    int len = r - l + 1;
    int p = logTable[len];

    return merge(sparse[p][l],sparse[p][r - (1<<p) + 1]);
}

int query(int l, int r, vector<vector<int> > &sparse)
{
    // Used for non Idempotent queries: Sum O(logn)
    int Log = log2(N);
    int sum = 0;
    int len = r - l + 1;
    int index = l;
    for(int i = 0; i <= Log; i++)
    {
        if(len&(1<<i))
        {
            sum += sparse[i][index];
            index += (1<<i);
        }
    }
    return sum;
}

signed main()
{
    int n , q;
    cin>>n>>q;
    N = n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int Log = log2(n);

    logTable.resize(n+1);

    for(int i = 2; i <= n; i++)logTable[i] = 1 + logTable[i/2];

    vector<vector<int> > sparse(Log + 1, vector<int> (n,0));

    build(sparse,arr);

    while(q--)
    {
        int l, r;
        cin>>l>>r;
        cout<<query(l-1,r-1,sparse)<<endl;
    }

}