//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;

        map<char, int>mp;

        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }

        int oneCount = 0, evenCount = 0;

        for(auto x:mp){
            if((x.second)==1){
                oneCount++;
            }else if((x.second)%2==0){
                evenCount+=x.second;
            }
            else{
                if(x.second>3){
                    evenCount+=(x.second-3);
                }
            }
        }

        if(oneCount<=evenCount/2){
            cout<<"YES";
        }else{
            cout<<"NO";
        }
        cout<<"\n";
    }
}