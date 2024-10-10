/*
    String matching: Returns a vector with indexes where there is match

*/
#include<bits/stdc++.h>

using namespace std;

vector<int> find_lps(string &pat)
{
    int m = pat.size();
    vector<int> lps(m,0);
    int len = 0;
    int i = 1;

    while(i < m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len != 0)
            {
                len = lps[len-1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMP(string &txt, string &pat)
{
    int n = txt.size();
    int m = pat.size();

    vector<int> lps(m,0);

    lps = find_lps(pat);
    
    int i = 0;
    int j = 0;

    vector<int> res;

    while((n-i)>=(m-j))
    {
        if(txt[i]==pat[j])
        {
            i++;
            j++;
        }

        if(j == m)
        {
            res.push_back(i-j+1);
            j = lps[j-1];
        }
        else if(i < n && txt[i] != pat[j])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else i++;
        }
    }

    return res;
}

int main()
{
    string text;
    string pat;
    cin>>text;
    cin>>pat;

    vector<int> res;

    res = KMP(text,pat);

    for(auto &it : res)
    {
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}