//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int et[n+1];

    for(int i=0;i<=n;i++){
        et[i]=i;
    }

    for(int i=2;i<=n;i++){
        if(et[i]==i)
        {
            for(int j=i*2;j<=n;j+=i)
            {
                et[j] = ((et[j]*(i-1))/i);
            }

            et[i]=i-1;
        }
    }

    cout<<et[n];

}