#include<bits/stdc++.h>

using namespace std;

int Boyer(int n, vector<int> &arr)
{
    int candidate = -1, votes = 0;

    for (int i = 0; i < n; i++)
    {
        if(votes == 0)
        {
            votes++;
            candidate = arr[i];
        }
        else
        {
            if(arr[i] == candidate)votes++;
            else votes--;
        }
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if(candidate == arr[i])cnt++;
    }

    if(cnt>n/2) return candidate;

    return -1;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<Boyer(n,arr)<<endl;
}