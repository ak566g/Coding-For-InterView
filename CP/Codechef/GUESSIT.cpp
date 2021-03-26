//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>odd;

void oddFactorNos(){
    for(int i=1;i<=1000;i++){
        odd.push_back(i*i);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    oddFactorNos();
    int t;
    cin>>t;


    while(t--){
        for(int i=0;i<odd.size();i++){
            cout<<odd[i]<<"\n";
            fflush(stdout);
            int response;
            cin>>response;
            // cout<<flush;
            if(response)
                break;
            if(response==-1)
            {
                return 0;
            }
        }
    }
}