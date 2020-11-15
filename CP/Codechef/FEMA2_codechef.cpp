//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n, k;
        cin>>n>>k;

        string s;
        cin>>s;

        int maxAns=0;

        for(int i=0;i<n;i++)
        {
            if(s[i]=='I')
            {
                int sheet=0;
                int localCount=0;
                int j=i-1;
                while(j>=0)
                {
                    if(s[j]==':')
                    {
                        sheet++;
                    }
                    else if(s[j]=='X')
                    {
                        break;
                    }
                    else if(s[j]=='M')
                    {
                        int power = k + 1 -(abs(j-i)) - sheet;
                        if(power>0)
                        localCount++;
                        else
                        {
                            break;
                        }
                        
                    }
                    j--;
                }

                j=i+1;
                sheet=0;
                while(j<n)
                {
                    if(s[j]==':')
                    {
                        sheet++;
                    }
                    else if(s[j]=='X')
                    {
                        break;
                    }
                    else if(s[j]=='M')
                    {
                        int power = k + 1 -(abs(j-i)) - sheet;
                        if(power>0)
                        localCount++;
                        else
                        {
                            break;
                        }
                    }
                    j++;
                }

                if(localCount>maxAns)
                maxAns=localCount;
            }
        }
        cout<<maxAns<<"\n";
    }
}