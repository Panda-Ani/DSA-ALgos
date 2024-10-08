#include<bits/stdc++.h>

using namespace std;

#define int long long int

const int base = 31;
const int mod = 1e9+7;

void make_hash(string &s, vector<int> &pow, vector<int> &hash)
{
    int n = s.size();

    pow[0] = 1;
    hash[0] = 0;

    for(int i = 1; i <= n; i++)
    {
        pow[i] = (pow[i-1]*base)%mod;
    }

    for(int i = 1; i <= n; i++)
    {
        hash[i] = ((hash[i-1])*base + (s[i-1] - 'a' + 1))%mod;
    }

    return;
}

int get_hash(int l, int r, vector<int> &hash, vector<int> &pow)
{
    long long ans = (mod + (hash[r] -hash[l-1]*pow[r-l+1])%mod)%mod;

    return ans;
}

signed main()
{
    string s1;
    string s2;

    cin>>s1;
    cin>>s2;

    int n = s1.size();
    int m = s2.size();
    vector<int> pow1(n+1);
    vector<int> hash1(n+1);
    vector<int> pow2(m+1);
    vector<int> hash2(m+1);

    make_hash(s1,pow1,hash1);

    make_hash(s2,pow2,hash2);

    int ans = 0;

    for(int i = 1; i <= n; i++)
    {
        int a = get_hash(i,i+m-1,hash1,pow1);
        int b = get_hash(1,m,hash2,pow2);
        if(a == b)
        {
            ans++;
        }
            cout<<a<<" "<<b<<endl;
    }

    cout<<ans<<endl;


}