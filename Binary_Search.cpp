#include<bits/stdc++.h>

using namespace std;

bool binary_search(int n, int key, vector<int> &arr)
{
    int lo = 0;
    int hi = n - 1;

    while(lo <= hi)
    {
        int mid = (lo+hi)>>1;

        if(arr[mid] == key)
        {
            return true;
        }
        else if(arr[mid] > key)
        {
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }

    return false;
}

int main()
{
    int n, key;
    cin>>n>>key;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout<<binary_search(n,key,arr)<<endl;

    return 0;
}