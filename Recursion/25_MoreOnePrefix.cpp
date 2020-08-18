// Print N-bit binary numbers having more 1’s than 0’s in all prefixes
// Given a positive integer n, print all n-bit binary numbers having more 1’s than 0’s for any prefix of the number.

#include<bits/stdc++.h>
using namespace std;

void printAllBinary(int n, string output, int one, int zero)
{
    if(n==0)
    {
        cout<<output<<"\n";
        return;
    }

    if(one>zero)
    {
        printAllBinary(n-1, output+"1", one+1, zero);
        printAllBinary(n-1, output+"0", one, zero+1);
    }
    else{
        printAllBinary(n-1, output+"1", one+1, zero);
    }
}

int main()
{
    int n;
    cin>>n;
    string output="";
    int one =0,zero=0;
    printAllBinary(n, output ,one , zero);
}