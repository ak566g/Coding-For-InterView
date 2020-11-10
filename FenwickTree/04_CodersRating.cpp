#include <bits/stdc++.h>
using namespace std;

class Coder{
  public:
    int x, y, index;
};


bool cmp(Coder &c1, Coder &c2)
{
    if(c1.x==c2.x)
    {
        return c1.y<c2.y;
    }
    
    return c1.x<c2.x;
}

int query(int val, int *bit)
{
    int count=0;
    for( ;val>0; val -= (val & (-val)))
    {
        count+=bit[val];
    }
    return count;
}

void update(int val, int *bit)
{
    for(;val<=100000; val += (val &(-val)))
    {
        bit[val]++;
    }
}

int main()
{
    int n;
    cin>>n;
    
    Coder *coder = new Coder[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>coder[i].x>>coder[i].y;
        coder[i].index=i;
    }
    
    sort(coder, coder+n, cmp);
    
    int *bit = new int[100001];
    memset(bit,0,sizeof(bit));
    int *ans = new int[n];
    
    for(int i=0;i<n;)
    {
        int endIndex=i;
        while(endIndex<n && coder[i].x==coder[endIndex].x && coder[i].y==coder[endIndex].y)
        {
            endIndex++;
        }
        
        for(int j=i;j<endIndex;j++)
        {
            ans[coder[j].index]=query(coder[j].y , bit);
        }
        
        for(int j=i;j<endIndex;j++)
        {
            update(coder[j].y, bit);
        }
        
        i = endIndex;
    }
    
    for(int i=0; i<n ;i++)
    {
        cout<<ans[i]<<"\n";
    }
    
    return 0;
}
