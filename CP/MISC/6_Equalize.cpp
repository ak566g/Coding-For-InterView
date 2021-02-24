//by Ankita Gupta

// You are given two binary strings a and b of the same length. You can perform the following two operations on the string a:

// Swap any two bits at indices i and j respectively (1≤i,j≤n), the cost of this operation is |i−j|, that is, the absolute difference between i and j.
// Select any arbitrary index i (1≤i≤n) and flip (change 0 to 1 or 1 to 0) the bit at this index. The cost of this operation is 1.
// Find the minimum cost to make the string a equal to b. It is not allowed to modify string b.

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    string a;
    string b;
    cin>>a;
    cin>>b;

    int count=0, i=0;

    while(i<n)
    {
        if(a[i]!=b[i])
        {   
            if(i+1<n&&a[i]!=a[i+1]&&a[i+1]!=b[i+1]){
                i+=2;
            }else{
                i++;
            }
            count++;
        }else{
            i++;
        }
    }
    cout<<count;
    
}