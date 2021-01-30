//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        int a[n];
        bool  slow=false;
        int count =0, botcount=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        for(int i=0;i<n;i++){
            if(a[i]<=1 && a[i]!=-1){
                botcount++;
            }

            if(a[i]>=0){
                count++;
            }

            if(a[i]>k){
                slow=true;
            }
        }

        if(count<ceil((1.0)*n/2)){
            cout<<"Rejected";
        }
        else if(slow){
            cout<<"Too slow";
        }
        else if(botcount==n){
            cout<<"Bot";
        }
        else{
            cout<<"Accepted";
        }
        cout<<"\n";
    }
}