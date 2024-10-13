#include<bits/stdc++.h>

using namespace std;

const int N = 1e7 + 10;

vector<bool> prime;

void sieve()
{
    for(int i = 2; i*i < N; i++)
    {
        if(prime[i])
        {
            for(int j = i*i; j < N; j += i)
            {
                prime[j] = false;
            }
        }
    }
}

int main()
{
    int n;
    cin>>n;

    prime = vector <bool> (N,true);

    sieve();

    if(prime[14])cout<<"YES"<<'\n';
    else cout<<"NO\n";

    return 0;
}