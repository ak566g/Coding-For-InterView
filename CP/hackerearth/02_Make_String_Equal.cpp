#include<bits/stdc++.h>
using namespace std;

int sortCount(string s)
{
    int hash[26];

    for(int i=0;i<26;i++)
    {
        hash[i]=-1;
    }

    for(int i=0;i<s.size();i++)
    {
        if(hash[s[i]-'a']==-1)
        {
            hash[s[i]-'a']=i;
        }
    }

    int count = 0;
    for(int i=0;i<26;i++)
    {
        int repeat = 0;
        int index = hash[i];
        if(index>=0){
            for(int j=index;j<s.size();j++)
            {
                if(s[index]==s[j])
                {
                    repeat++;
                }
                else if(s[index]>s[j])
                {
                    count+=repeat;
                }
            }
        }
    }

    return count;
}


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        string p, q;
        cin>>p>>q;

        int scp = sortCount(p);
        int scq = sortCount(q);
        // cout<<scp<<" "<<scq<<"\n";
        
        int hashp[26];
        int hashq[26];

        for(int i=0;i<26;i++)
        {
            hashp[i]=0;
            hashq[i]=0;
        }
        
        for(int i=0;i<n;i++){
            hashp[p[i]-'a']++;
            hashq[q[i]-'a']++;
        }
        bool flag=false, repeat=false;;
        for(int i=0;i<26;i++)
        {
            if(hashp[i]!=hashq[i])
            {
                flag=true;
            }
            if(hashp[i]>=2){
                repeat=true;
            }
        }

        if(flag==1||(n<=2&&p!=q)){
            cout<<"NO";
        }
        else if(n==1&&p==q){
            cout<<"YES";
        }
        else if((abs(scp-scq)%2==0||(repeat==true)))
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
