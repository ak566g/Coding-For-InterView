#include<bits/stdc++.h>
using namespace std;

void printPatt(int n)
{
    for(int i=0;i<n;i++)
    cout<<"*";

    //galti no 1
    cout<<endl;

    int n1= n/2;

    // upper half
    for(int i=1;i<=n1;i++)
    {
        // galti no 2
        for(int j=1;j<=n1-i+1;j++)
        cout<<"*";

        for(int l=1;l<=2*i-1;l++)
        cout<<" ";
        
        for(int k=1;k<=n1-i+1;k++)
        cout<<"*";

        cout<<endl;
    }

    for(int i=n1-1;i>=1;i--)
    {
        for(int j=1;j<=n1-i+1;j++)
        cout<<"*";

        for(int l=1;l<=2*i-1;l++)
        cout<<" ";

        // galti no 3
        for(int k=1;k<=n1-i+1;k++)
        cout<<"*";
        
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    cout<<"*";
}

int main()
{
    int n;
    cin>>n;
    printPatt(n);
}


1. There should be new line after line 4.
2. At line 11 loop should run till n1-i+1 instead of n1-i
3. At line 31 condition in for loop is wrong  it should be k<= n1-i+1 instead i<=n1-i+1