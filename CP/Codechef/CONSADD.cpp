//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while (t--)
    {
        int r, c, x;
        cin>>r>>c>>x;

        int a[r][c], b[r][c];
        int diff[r][c];

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cin>>b[i][j];
                diff[i][j] = b[i][j]-a[i][j];
            }
        }

        for(int i=0;i<r;i++){
            for(int j=0;j<c; j++){
                if(diff[i][j]!=0){
                    int k = j;
                    int start = 0;
                    int sub = diff[i][j];
                    if(c-k>=x){
                        while(start<x){
                            diff[i][k] -= sub;
                            start++;
                            k++;
                        }
                    }
                }
            }
        }

        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                if(diff[j][i]!=0){
                    int k = j;
                    int start = 0;
                    int sub = diff[j][i];

                    if(r-k>=x){
                        while(start<x){
                            diff[k][i] -= sub;
                            start++;
                            k++;
                        }
                    }
                }
            }
        }

        bool ans = true;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(diff[i][j]!=0){
                    ans = false;
                    break;
                }
            }
        }
        
        if(ans){
            cout<<"Yes";
        }else{
            cout<<"No";
        }
        cout<<"\n";
    }
    
}