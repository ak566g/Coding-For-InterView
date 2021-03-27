//by Ankita Gupta

#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while (t--)
    {
        int n;
        cin>>n;
        int odd=0;
        vector<int>num(n);
        for(int i=0;i<n;i++){
            cin>>num[i];
            if(num[i]%2==1){
                odd++;
            }
        }

        if(odd%2==0){
            cout<<0;
        }else{
            int ans = -1;
            for(int i=0;i<n;i++){
                int p = ceil((num[i]*1.0)/2)-1;
                p = max(0, p);
                if(p==0 && num[i]%2==0){
                    ans = 1;
                    break;
                }
            }
            cout<<ans;
        }
        cout<<"\n";
    }
    

}