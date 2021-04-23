//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }    

    int *ans = new int[n];

    for(int i=0;i<n;i++){
        ans[i]=1;
    }

    for(int i=2;i<n;i++){
        int j=i-1;
        while(j>=0 && a[j])
    }

}