//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

class FROG{
    public:
        int index;
        int l;
        int w;
};

int main(){

    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        FROG frogs[n];

        for(int i=0;i<n;i++){
            cin>>frogs[i].w;
        }
        for(int i=0;i<n;i++){
            cin>>frogs[i].l;
            frogs[i].index = i+1;
        }

        bool ans = false;
        int count = 0;

        while(!ans){
            bool flag = true;
            for(int i = 0; i<n ;i++){
                for(int  j = 0; j<n ;j++){
                    if(frogs[i].w > frogs[j].w && frogs[i].index <= frogs[j].index){
                        flag = false;
                        break;
                    } 
                }
                if(!flag){
                    break;
                }
            }

            if(flag){
                ans = true;
                break;
            }

            for(int i  = 0; i< n ;i++){
                for(int j = 0; j< n; j++){
                    if(i!=j){
                        if(frogs[i].w > frogs[j].w && frogs[i].index <= frogs[j].index){
                            while(frogs[i].index <= frogs[j].index){
                                frogs[i].index += frogs[i].l;
                                count++;
                            }
                        }
                    }
                }
            }
        }
        cout<<count<<"\n";
    }
}