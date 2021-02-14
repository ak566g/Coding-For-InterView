#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;

    ll *a = new ll[n+1];
    ll *sum = new ll[n+1];
    a[0]=0;
    sum[0]=0;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        a[i]+=a[i-1];
        sum[i]=0;
    }

    int index[501];
    index[0]=0;

    for(int i=1;i<=500;i++){
        index[i]=i+index[i-1];
    }

    int i=1;
    while(i<=n){
        int j=1;
        int idx;
        while(i-1+index[j]<=n){
            j++;
        }
        if(i-1+index[j]>n){
            idx=i-1+index[j-1];
        }else{
            idx=i-1+index[j];
        }
        sum[i]=a[idx]-a[i-1];
        i++;
    }

    ll maxans = sum[1];

    for(int i=1;i<=n;i++){
        maxans= max(sum[i], maxans);
    }

    cout<<maxans;
}