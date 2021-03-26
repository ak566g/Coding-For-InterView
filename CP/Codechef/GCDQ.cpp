//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, q;
        cin>>n>>q;
        int a[n+2];
        a[0]=0;
        a[n+1]=0;
        
        int suffix[n+2]={0};
        int prefix[n+2]={0};

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        for(int i=1;i<=n;i++){
            prefix[i] = gcd(a[i], prefix[i-1]);
        }

        for(int i=n;i>=1;i--){
            suffix[i]=gcd(a[i], suffix[i+1]);
        }

        while(q--){
            int l, r;
            cin>>l>>r;

            cout<<gcd(prefix[l-1],suffix[r+1])<<"\n";
        }

    }
}