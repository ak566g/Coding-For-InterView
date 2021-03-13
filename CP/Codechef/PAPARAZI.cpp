//by Ankita Gupta

#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<pair<int, int>>v(n);

        for(int i=0;i<n;i++){
            int x;
            cin>>x;

            v[i] = {i, x};
        }
        int maxAns = 1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                bool flag = true;
                double slope1 = ((1.0)*(v[i].ss - v[j].ss))/((1.0)*(v[i].ff - v[j].ff));
                for(int k=i+1;k<=j-1;k++){
                    double slope2 = ((1.0)*(v[k].ss - v[i].ss))/((1.0)*(v[k].ff - v[i].ff));
                    
                    if(slope2>slope1){
                        flag=false;
                        break;
                    }
                }

                if(flag){
                    maxAns = max(maxAns, j-i);
                }
            }
        }

        cout<<maxAns<<"\n";
    }
}