// Given a integer K. Task is Print All binary string of size K (Given number).
// Generate all binary strings without consecutive 1’s


#include<bits/stdc++.h>
using namespace std;


void generateStrings(int n, string s)
{
    if(n==0){
        cout<<s<<endl;
        return;
    }

    if(s.size()>=1)
    {
        if(s[s.size()-1]=='1')
        {
            generateStrings(n-1,s+"0");
        }
        else
        {
            generateStrings(n-1,s+"0");
            generateStrings(n-1,s+"1");
        }
        
    }
    else
    {
            generateStrings(n-1,s+"0");
            generateStrings(n-1,s+"1");
    }
    
}

int main()
{
    int n;
    cin>>n;

    generateStrings(n,"");
}