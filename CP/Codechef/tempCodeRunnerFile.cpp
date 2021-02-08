//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;


void subsequence(int *a, vector<int>sub, int *sum, int N){
    if(N==0){
        return;
    }

    int n = sub.size();

    if(n>0){
        int index = n-1;
        int x = 0;

        for(int i=0;i<n;i++){
            x = sub[i]^x;
        }

        sum[index]+=x;
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