//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string s;
        cin>>s;

        bool flag=false;

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[n-1])
            {
                flag=true;
                break;
            }
        }   

        if(flag)
        {
            cout<<"YES";
        }
        else
        {
            cout<<"NO";
        }

        cout<<endl;
        
    }

}