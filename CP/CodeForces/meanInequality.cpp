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
        n = 2*n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        sort(a.begin(), a.end());

        vector<int>ans(n);
        int start = 0, end = n-1;
        int idx = 0;

        for(idx = 0; idx<n ; idx++){
            if(idx%2==0){
                ans[idx] = a[start];
                start++;
            }else{
                ans[idx] = a[end];
                end--;
            }
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}