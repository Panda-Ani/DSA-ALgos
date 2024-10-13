#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

long long power(long long a, long long b)
{
    long long result = 1;
    while(b>0)
    {
        if(b&1)result = (result*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }

    return result;
}

long long inv_mod(long long a)
{
    return power(a,mod-2);
}

int main()
{
    long long a;
    cin>>a;
    cout<<inv_mod(a)<<endl;
}