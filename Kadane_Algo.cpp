// Maximum Subarray Sum
#include<bits/stdc++.h>

using namespace std;

int kadane(int n, vector<int> &arr)
{
    int res = arr[0];
    int maxEnding = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxEnding = max(maxEnding + arr[i], arr[i]);
        res = max(res,maxEnding);
    }

    return res;
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

    cout<<kadane(n,arr)<<endl;
}