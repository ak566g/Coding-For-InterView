//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int* buildZ(string s, string t)
{
    string str=t+"$"+s;
    int n=str.size();
    int x=s.size();
    int y=t.size();

    int *z= new int[n];

    z[0]=0;

    int l=0, r=0;

    for(int i=1;i<n;i++)
    {
        if(i>r)
        {
            l=i;
            r=i;

            while(r<n && str[r-l]==str[r])
            {
                r++;
            }
            z[i]=r-l;
            r--;
        }

        else{
            int k=i-l;
            if(z[k]<=r-i)
            {
                 z[i]=z[k];
            }else
            {
                l=i;
                while(r<n && str[r-l]==str[r])
                {
                    r++;
                }
                z[i]=r-l;
                r--;
            }
            
        }
        
    }
    return z;
}

int main(){

    string s, t;
    cin>>s>>t;

    int *z = buildZ(s, t);

    string temp=t+"$"+s;
    int n=temp.size();

    for(int i=0;i<n;i++)
    {
        if(z[i]==t.size())
        {
            cout<<i-t.size()-1<<" ";
        }
    }

}