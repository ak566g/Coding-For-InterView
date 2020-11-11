//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, k;
    cin>>n>>k;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int count=0;

    for(int i=0; i<(1<<n) ;i++)
    {
        int sum=0;
        int mask=i;
        for(int j=0; j<n; j++)
        {
            if(mask & (1<<j))
            {
                sum+=a[j];
            }
        }

        if(sum==k)
        {
            count++;
        }
    }
    cout<<count;
}