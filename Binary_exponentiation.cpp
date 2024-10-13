#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

long long power(long long a, long long b)
{
    long long res = 1;

    while(b>0)
    {
        if(b&1)res = (res*a)%mod;
        a = (a*a)%mod;
        b = b>>1;
    }

    return res;
}

int main()
{
    long long a,b;
    cin>>a>>b;
    cout<<power(a,b)<<endl;
}