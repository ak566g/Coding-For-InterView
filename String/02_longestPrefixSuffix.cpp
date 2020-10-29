//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int* getLps(string pattern)
{
    int len = pattern.size();
    int *lps = new int[len];

    lps[0]=0;
    int i=1;
    int j=0;

    if(len==1)
    {
        return lps;
    }

    while(i<len)
    {
        if(pattern[i]==pattern[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else if(j==0)
        {
            lps[i]=0;
            i++;
        }
        else
        {
            j=lps[j-1];
        }
        
    }
    return lps;
}

int main(){
    string s;
    cin>>s;
    int *lps = new int[s.size()];
    lps=getLps(s);

    for(int i=0;i<s.size();i++)
    {
        cout<<lps[i]<<" ";
    }
}
