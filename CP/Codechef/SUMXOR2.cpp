//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;


void subsequence(int *a, vector<int>sub, int *sum, int N){
    if(N==0){
        int n = sub.size();
        int index = n;
        int x = 0;

        for(int i=0;i<n;i++){
            x = sub[i]^x;
        }

        sum[index]+=x;    
        return;
    }
    subsequence(a+1, sub, sum, N-1);
    sub.push_back(a[0]);
    subsequence(a+1, sub, sum, N-1);
    
}

int main(){
    int n;
    cin>>n;

    int v[n];
    for(int i=0; i<n; i++){
        cin>>v[i];
    }

    vector<int>subs;
    int sum[n+1];

    for(int i=0;i<=n;i++){
        sum[i]=0;
    }

    subsequence(v, subs, sum, n);
    
    for(int i=1; i<=n; i++){
        sum[i]+=sum[i-1];
    }

    int q;
    cin>>q;

    while(q--){
        int m;
        cin>>m;

        cout<<sum[m]<<"\n";
    }
}