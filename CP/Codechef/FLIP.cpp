//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        string a;
        string b;
        cin>>a>>b;

        int count=0;

        for(int i=0;i<a.size();i++)
        {
            if(a[i]!=b[i])
            {
                count++;
            }
        }
        
        cout<<count/2+1<<"\n";
    }
}