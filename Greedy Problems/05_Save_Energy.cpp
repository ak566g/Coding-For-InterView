//by Ankita Gupta
//Problem Link
//https://www.codechef.com/problems/SVENGY

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;

    long *a= new long[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    long cost=0;
    long i=0;

    for(i=0;i<n-1;)
    {
        long j;
        for(j=i+1;j<n-1; j++)
        {
            if(abs(a[i])>abs(a[j]) || (a[i]== a[j] && a[i]>0))
            break;
        }
        cost+=(j-i)*a[i] + (j*j - i*i) *a[i]*a[i];
        i=j;
    }

    cout<<cost;
    return 0;
}