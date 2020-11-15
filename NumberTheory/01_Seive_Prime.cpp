
#include<bits/stdc++.h>
using namespace std;

bool seive[1000001];

void init()
{
	memset(seive, true, sizeof(seive));
    seive[0]=false;
    seive[1]=false;
    
    for(int i=2;i<=1000000;i++)
    {
        if(seive[i]==true)
        {
            for(int j=i+i ;j<=1000000; j+=i)
            {
                seive[j]=false;
            }
        }
    }
}

int main(){
	
    int n;
    cin>>n;
    init();
    int count=0;
    
    for(int i=1;i<=n;i++)
    {
        if(seive[i]==true)
            count++;
    }
    
    cout<<count;
    
	return 0;
}