//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        string pass;
        cin>>pass;

        bool hash[5];

        for(int i=0;i<5;i++)
        {
            hash[i]=0;
        }

        bool ans = true;
        if(pass.size()>=10)
        {
            hash[4]=1;

            for(int i=1;i<pass.size()-1;i++)
            {
                if(pass[i]>='A'&&pass[i]<='Z'){
                    hash[1]=true;
                }

                if(pass[i]>='0' && pass[i]<='9'){
                    hash[2]=true;
                }

                if(pass[i]=='@'||pass[i]=='#'||pass[i]=='%'||pass[i]=='&'||pass[i]=='?')
                {
                    hash[3]=true;
                }
            }

            for(int i=0;i<pass.size();i++)
            {
                if(pass[i]>='a'&&pass[i]<='z')
                {
                    hash[0]=true;
                }
            }
        }

        for(int i=0;i<5;i++)
        {
            if(hash[i]==false)
            {
                    ans=false;
            }
        }

        if(ans){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }

        cout<<endl;
    }
}