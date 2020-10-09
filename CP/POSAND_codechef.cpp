//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool two[1000001];

void init()
{
    two[0]=false;
    for(int i=1;i<=1000000;i++)
    {
        int x= i;
        if(!(x & (x-1))&&x)
        {
            two[i]=true;
        }
        else
        {
            two[i]=false;
        }
    }
}


vector<int> posand(int n)
{
    vector<int>v;

    if(two[n])
    {
        v.push_back(-1);
        return v;
    }
    else if(n==1)
    {
        v.push_back(1);
    }
    else if(n==3)
    {
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
    }
    else if(n==5)
    {
        v.push_back(2);
        v.push_back(3);
        v.push_back(1);
        v.push_back(5);
        v.push_back(4);
    }
    else 
    {
        v.push_back(2);
        v.push_back(3);
        v.push_back(1);
        v.push_back(5);
        v.push_back(4);

        for(int i=6;i<=n;i++)
        {
            if(two[i])
            {
                v.push_back(i+1);
                v.push_back(i);
                i++;
            }
            else
            {
                v.push_back(i);
            }
            
        }
    }

    return v;
}

int main(){

    init();
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int>v;

        v= posand(n);

        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";

        cout<<endl;
    }

}