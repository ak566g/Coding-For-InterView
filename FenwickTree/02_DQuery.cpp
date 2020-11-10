// https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;

class Query{
  public:
    int start, end, index;
};

bool cmp(Query &q1, Query &q2)
{
    return q1.end<q2.end;
}

void update(int index, int n, int value, int *bit)
{
    for(;index<=n;index += (index & (-index)))
    {
        bit[index]+=value;
    }
}


int queryTree(int index, int *bit)
{
    int ans=0;
    for(;index>0;index -= (index & (-index)))
    {
        ans+=bit[index];
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int *a = new int[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int q;
    cin>>q;
    Query *query = new Query[q];
    
    // We're first calculating all the queries then printing the answer.
    // This method falls under offline programming.
    for(int i=0;i<q;i++)
    {
        cin>>query[i].start>>query[i].end;
        query[i].index=i;
    }
    
    // Sorting the queries according to the end index.
    sort(query, query+q, cmp);
    
    // Here we'll store if the element is unique for now or not and will store last index.
    // Main idea is that, we'll calculate unique element till now so if we've found any duplicate element
    // then we'll go to previous element and decrement the count for there. 
    int *lastIndex = new int[1000001];
    int *bit = new int[n+1];
    int *ans = new int[q];
    
    for(int i=0;i<=1000000;i++)
    {
        lastIndex[i]=-1;
    }
    
    int total=0;
    int k=0;
    for(int i=1;i<=n;i++)
    {
        if(lastIndex[a[i]]!=-1)
        {
            update(lastIndex[a[i]], n, -1, bit);
            
        }
        else
        {
            total++;
        }
        
        lastIndex[a[i]]=i;
        update(i, n, 1, bit);
        
        
        while(k<q && query[k].end==i)
        {
            ans[query[k].index]= total - queryTree(query[k].start-1, bit);
            k++;
        }
    }
    
    
    for(int i=0;i<q;i++)
    {
        cout<<ans[i]<<"\n";
    }
    
    return 0;
}
