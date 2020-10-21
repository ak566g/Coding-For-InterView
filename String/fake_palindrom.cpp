//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int Palindrom(string s)
{
    int parity=0;
    vector<int>pa;
    pa.push_back(parity);

    for(int i=0;i<s.size();i++)
    {
        parity^=1<<(s[i]-'A');
        pa.push_back(parity);
    }

    int dp[200001];

    memset(dp, 0, sizeof(dp));

    int res=0;

    for(int i=0;i<pa.size();i++)
    {
        for(int j=-1;j<10;j++)
        {
            res+=dp[(1<<j)^pa[i]];
        }
        dp[pa[i]]++;
    }

    return res;

}


int main(){
    int t;
    cin>>t;

    while(t--)
    {
        string s;
        getline(cin,s);

        cout<<Palindrom(s)<<endl;
    }

}