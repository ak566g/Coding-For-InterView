//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int>v(n), temp(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
            temp[i]=v[i];
        }

        sort(temp.begin(), temp.end(), greater<int>());
        int count=0;

        for(int i=0;i<n;i++){
            if(temp[i]==v[i])
            count++;
        }

        if(count==n){
            cout<<"NO";
        }else{
            cout<<"YES";
        }

        cout<<"\n";
    }
}