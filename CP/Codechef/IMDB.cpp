//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, x;
        cin>>n>>x;

        vector<pair<int, int>>v;

        for(int i=0;i<n;i++){
            int s,r;
            cin>>s>>r;

            v.push_back({r,s});
        }
        sort(v.begin(),v.end());
        int ans = -1;
        for(int i=n-1;i>=0;i--){
            if(v[i].second<=x){
                ans = v[i].first;
                break;
            }
        }
        cout<<ans<<"\n";
    }
}