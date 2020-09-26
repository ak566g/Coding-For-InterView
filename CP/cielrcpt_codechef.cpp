//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){

    int menu[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
    int t;
    cin>>t;

    while(t--)
    {
        int p;
        cin>>p;
        
        int count=0;
        int i=11;

        while(i>=0)
        {
            while(p-menu[i]>=0)
            {
                p-=menu[i];
                count++;
            }

            i--;
        }
        cout<<count<<"\n";
    }

}