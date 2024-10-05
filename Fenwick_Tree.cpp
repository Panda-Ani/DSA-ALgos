#include<bits/stdc++.h>

// x&(-x) returns the last set bit

using namespace std;

const int N = 1e5+10;
int bit[N];

void update(int i, int x)
{
    for(; i < N; i+=(i&-i))bit[i] += x;
}

int sum(int i)
{
    int ans = 0;
    for(; i>0 ; i -= (i&-i))ans+=bit[i];
    return ans;
}

int main()
{
    int n, q;
    cin>>n>>q;

    vector<int> arr(n+1);

    for(int i = 1; i <= n; i++) // one-based indexing is necessary
    {
        cin>>arr[i];
        update(i,arr[i]);
    }

    while(q--)
    {
        int type;
        cin>>type;

        if(type == 1)
        {
            int i , x;
            cin>>i>>x;

            update(i, x - arr[i]);
            arr[i] = x;
        }
        else
        {
            int l, r;
            cin>>l>>r;

            cout<<sum(r) - sum(l-1)<<endl;
        }
    }

    return 0;
}