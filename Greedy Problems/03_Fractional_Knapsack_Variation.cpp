//by Ankita Gupta
// Problem Link
// https://www.codechef.com/problems/COFJP1M2


#include<bits/stdc++.h>
#define ll long long
using namespace std;

class worker{
    public:
    	ll time;	//ti
    	ll cost;	//xi
    	ll speed;	//yi
};

bool cmp(worker &w1, worker &w2)
{
    if(w1.time==w2.time)
    {
        if(w1.speed==w2.speed)
        {
            return w1.cost<w2.cost;
        }
        return w1.speed>w2.speed;
    }
    
    return w1.time<w2.time;
}

int main()
{
    int n;
    ll d;
    cin>>n>>d;
    
    worker w[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>w[i].time>>w[i].cost>>w[i].speed;
    }
    
    sort(w,w+n,cmp);
    ll cost=w[0].cost;
    ll area=0;
    int j=0;
    
    for(int i=1;i<n;i++)
    {
        area= area+ (w[i].time- w[i-1].time)*w[j].speed;
        
        if(area>=d)
            break;
        
        if(w[i].speed>w[j].speed)
        {
        	j=i;
            cost = cost + w[j].cost;
        }
    }
    
    cout<<cost;
    return 0;
}