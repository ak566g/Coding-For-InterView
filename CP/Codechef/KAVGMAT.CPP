//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int m, n, av;
        cin>>m>>n>>av;

        int mat[m][n];
        double sum[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>mat[i][j];
                sum[i][j]=mat[i][j];
            }
        }
        int len = min(m, n);
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=1;j<n;j++){
                sum[i][j]+=sum[i][j-1];
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                sum[j][i] += sum[j-1][i]; 
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<sum[i][j]<<" ";
            }
            cout<<"\n";
        }

        cout<<count<<"\n";

    }
}