// https://www.spoj.com/problems/KQUERY/
//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


class Event{
    public:
    int start, end;
    long long val;
    int i;
};

int bit[300002];
Event event[300002];
Event ans[300002];

bool cmp(Event &e1, Event &e2)
{
    if(e1.val==e2.val)
    {
        return e1.start>e2.start;
    }
    return e1.val>e2.val;
}

void update(int i, int n)
{
    //cout<<i<<" "<<n<<"\n";
    for(;i<=n;i+=(i&(-i)))
    {
        bit[i]++;
    }
}

int query(int i)
{
    int count=0;
    
    for(;i>0;i-=(i&(-i)))
    {
        count+=bit[i];
    }
    return count;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    memset(bit, 0, sizeof(bit));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        event[i].start =0;
        event[i].end = i;
        event[i].val = x;
    }

    int q;
    cin>>q;
    for(int i=n+1;i<=n+q;i++)
    {
        int start, end, val;
        cin>>start>>end>>val;
        event[i].start = start;
        event[i].end = end;
        event[i].val = val;
        event[i].i = n-i;
    }
    sort(event+1, event+n+q+1, cmp);

    int temp=1;
    for(int t=1;t<=n+q;t++)   
    {
        if(event[t].i==0)
        {
            update(event[t].end,n);
        }
        else
        {
            ans[temp].val = event[t].i;
            ans[temp++].end=query(event[t].end)-query(event[t].start-1);
        }
    }
    
    sort(ans, ans+q+1, cmp);
    for(int i=1;i<=q;i++)
    {
        cout<<ans[i].end<<"\n";
    }
}
