//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, m, k;
        cin>>n>>m>>k;
        int ans = 0;
        int i=1, j=1;
        
        while(i<=n && i<=m){
            if(i%2==1){
                ans = ans^(k+i+1);
            }
            i++;
        }
        int j=2;

        if(i<m){
            while(i)
        }

    }
}