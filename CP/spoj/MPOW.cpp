//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

ll I[55][55], M[55][55];

void multiply(ll A[][55], ll B[][55], int d){

    ll temp[55][55];
    memset(temp, 0, sizeof(temp));

    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            temp[i][j]=0;
            for(int k=0;k<d;k++){
                temp[i][j] = (temp[i][j] + (A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }

    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            A[i][j]=temp[i][j];
        }
    }
}

void power(ll M[][55], int d, int p){
    memset(I, 0, sizeof(I));
    for(int i=0;i<d;i++){
        I[i][i]=1;
    }   


    // naive
    // for(int i=1;i<=p;i++){
    //     multiply(I, M, d);
    // }

    while (p)
    {
        if(p%2){
            multiply(I, M, d);
            p--;
        }else{
            multiply(M,M,d);
            p=p/2;
        }
    }
    

    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            M[i][j]=I[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while (t--)
    {
        int n, p;
        cin>>n>>p;

        
        memset(M, 0, sizeof(M));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>M[i][j];
            }
        }

        power(M, n,p);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<M[i][j]<<" ";
            }
            cout<<endl;
        }

    }
    

}