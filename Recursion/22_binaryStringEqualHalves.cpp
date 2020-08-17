// All possible binary numbers of length n with equal sum in both halves

#include<bits/stdc++.h>
using namespace std;

void printAllStrings(int n, string s1, string s2)
{
    if(n==0)
    {
        cout<<s1<<s2<<endl;
        return;
    }

    if(n==1)
    {
        cout<<s1<<"0"<<s2<<endl;
        cout<<s1<<"1"<<s2<<endl;
        return;
    }

    printAllStrings(n-2,s1+'1',s2+'1');
    printAllStrings(n-2,s1+'0',s2+'0');
}


int main()
{
    int n;
    cin>>n;

    printAllStrings(n,"", "");
}
