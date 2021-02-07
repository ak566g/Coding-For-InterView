//by Ankita Gupta

// 3
// 2
// suf mas
// 3
// good game guys
// 4
// hell bell best test

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<string>v(n);
        unordered_map<string, int>um;
        for(int i=0; i<n; i++){
            cin>>v[i];
            um[v[i]]=1;
        }


        int ans = 0;

        for(int i = 0; i<n ; i++){
            for(int j = i+1; j<n; j++){
                if(v[i][0]!=v[j][0]){
                    string a = v[i];
                    string b = v[j];

                    swap(a[0], b[0]);

                    if(um[a]==0 && um[b]==0){
                        ans++;
                    }
                }
            }
        }

        cout<<ans*2<<"\n";
    }
}