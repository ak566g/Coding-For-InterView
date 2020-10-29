//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int* findLPS(string p)
{
    int n=p.size();
    int *lps= new int[n];
    lps[0]=0;
    int j=0;
    int i=1;

    while(i<n)
    {
        if(p[i]==p[j])
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
        else{
            j=lps[j-1];
        }
    }

    return lps;
}


bool isSubstring(string s, string p)
{
    int *lps= findLPS(p);
    int n=s.size(), m=p.size();
    int i=0 ,j=0;

    while(i<n && j<m)
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else{
            j=lps[j-1];
        }
    }
    
    if(j==m)
    return true;

    return false;
}

int main(){

    string s,p;
    cin>>s>>p;

    cout<<isSubstring(s,p);

}