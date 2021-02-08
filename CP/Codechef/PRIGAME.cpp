//by Ankita Gupta

#include<bits/stdc++.h>
#define inf 1000001
using namespace std;

int primeCount[inf];



void init(){
    for(int i=0;i<inf;i++){
        primeCount[i]=1;
    }   

    primeCount[0]=0;
    primeCount[1]=0;

    for(int i=2;i*i<inf;i++){
        if(primeCount[i]==1){
            for(int j=i*i;j<inf;j+=i){
                primeCount[j]=0;
            }
        }
    }

    for(int i=2;i<inf;i++){
        primeCount[i]+=primeCount[i-1];
    }
}

int main(){
    init();

    int t;
    cin>>t;

    while(t--)
    {
        int x, y;
        cin>>x>>y;

        if(primeCount[x]<=y){
            cout<<"Chef";
        }
        else{
            cout<<"Divyam";
        }
        cout<<"\n";
    }
}