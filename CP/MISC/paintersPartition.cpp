#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

bool check(int *a, int k, int n, ll mid){

    int count=1;
    ll sum=0;
    for(int i=0;i<n;i++){
        if(a[i]>mid){
            return false;
        }

        if(sum+a[i]>mid){
            count++;
            sum=a[i];
            if(count>k)
            return false;
        }else{
            sum+=a[i];
        }
    }

return true;
}


ll partition(int *a, int k, int n){
    ll start=0;
    ll end=0;

    for(int i=0;i<n;i++){
        start=max((ll)a[i],start);
        end+=a[i];
    }

    ll ans=-1;
    while(start<=end){
        ll mid=start+(end-start)/2;

        if(check(a,k,n,mid)){
            ans=mid;
            end=mid-1;
        }else{
            start=mid+1;
        }
    }

    return ans;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin>>k>>n;
        int *a= new int[n];
        
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        cout<<partition(a,k,n)<<"\n";

    }
}