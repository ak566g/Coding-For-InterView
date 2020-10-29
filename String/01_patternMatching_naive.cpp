//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool isMatching(string s, string p)
{
    int n=s.size();
    int m=p.size();

    for(int i=0;i<=(n-m);i++)
    {
        bool isFound=true;
        for(int j=0;j<m;j++)
        {
            if(s[i+j]!=p[j])
            {
                isFound=false;
                break;
            }
        }
        if(isFound==true)
        {
            return true;
        }
    }

    return false;
}

int main(){
    string s, p;
    cin>>s>>p;

    cout<<isMatching(s,p)<<"\n";
}