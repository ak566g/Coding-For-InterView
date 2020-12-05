#include <bits/stdc++.h>
#define max 100001
using namespace std;

bool seive[max];

void init()
{
    memset(seive, true, sizeof(seive));
    seive[0]=false;
    seive[1]=false;
    
    for(int i=2;i*i<max;i++)
    {
        if(seive[i]==true)
        {
            for(int j=i*2;j<max;j+=i)
            {
                seive[j]=false;
            }
        }
    }
}


void segmentedSeive(int l, int r)
{
    vector<int>v;
    
    for(int i=2;i<max;i++)
    {
        if(seive[i]==true)
        {
            v.push_back(i);
        }
    }
    
    bool ss[r-l+1];
    memset(ss, true, sizeof(ss));
    
//     // cout<<v.size()<<"\n";
    
    for(int i=0;(v[i]*v[i])<r;i++)
    {
        int n = v[i];
		int start = (l/n)*n;  
        if(start<l){
            start+=n;
        }
        for(int j=start;j<=r;j+=n)
        {
            ss[j-l]=false;
        }
        
        if(start == n)
        {
            ss[start-l]=true;
        }
    }
    
    for(int i=0 ;i<=r-l ;i++)
    {
        if(ss[i]==true)
        {
            cout<<i+l<<"\n";
        }
    }
}

int main()
{
    int t;
    cin>>t;
    
    init();
    while(t--)
    {
        int start, end;
        cin>>start>>end;
        segmentedSeive(start, end);
        
        
    }
	return 0;
}