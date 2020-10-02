#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int s;
    int ss;
};

class Lazy{
    public:
    int set;
	int add;
};

Tree tree[400000];
Lazy lazy[400000];
int a[100000];

void buildTree(int start, int end, int ti)
{
    if(start==end)
    {
        tree[ti].s=a[start];
        tree[ti].ss=a[start]*a[start];
        return;
    }
    
    
    int mid = (start + end)/2;
    
    buildTree(start, mid, 2*ti);
    buildTree(mid+1, end, 2*ti+1);
    
    tree[ti].s= tree[2*ti].s + tree[2*ti+1].s;
    tree[ti].ss= tree[2*ti].ss + tree[2*ti+1].ss;
}


Tree queryTree(int start, int end, int l, int r, int ti)
{
    if(start>r || end <l)
    {
        Tree ans;
        ans.s=0;
        ans.ss=0;
        return ans;
    }
    if(lazy[ti].set!=0)
    {
        tree[ti].ss = (r-l+1)*lazy[ti].set*lazy[ti].set;
        tree[ti].s = (r-l+1)*lazy[ti].set;
        
        if(start!=end)
        {
            lazy[2*ti].set=lazy[ti].set;
            lazy[2*ti+1].set=lazy[ti].set;
        }
        
        lazy[ti].set=0;
    }
    
    if(lazy[ti].add!=0)
    {
        tree[ti].ss+=((r-l+1)*(lazy[ti].add*lazy[ti].add) + 2 * tree[ti].s * lazy[ti].add);
        tree[ti].s+=(r-l+1)*lazy[ti].add;
        
        if(start!=end)
        {
            lazy[2*ti].add+=lazy[ti].add;
            lazy[2*ti+1].add+=lazy[ti].add;
        }
        
        lazy[ti].add=0;
    }
    
    
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start + end)/2;
    
    Tree left = queryTree(start, mid, l, r, 2*ti);
    Tree right = queryTree(mid+1, end, l, r, 2*ti+1);
    
    Tree ans;
    ans.ss = left.ss+right.ss;
    ans.s = left.s+right.s;
    
    return ans;
}

void addInRange(int start, int end, int l, int r, int ti, int val)
{
    if(start>end)
        return;
    
    
    if(lazy[ti].set!=0)
    {
        tree[ti].ss = (r-l+1)*lazy[ti].set*lazy[ti].set;
        tree[ti].s = (r-l+1)*lazy[ti].set;
        
        if(start!=end)
        {
            lazy[2*ti].set=lazy[ti].set;
            lazy[2*ti+1].set=lazy[ti].set;
            lazy[2*ti].add=0;
            lazy[2*ti+1].add=0;
        }
        
        lazy[ti].set=0;
    }
    
    if(lazy[ti].add!=0)
    {
        tree[ti].ss+=(2*tree[ti].s*lazy[ti].add) +(r-l+1)*(lazy[ti].add*lazy[ti].add);
        tree[ti].s+= (r-l+1)*lazy[ti].add;
        
        if(start!=end)
        {
            lazy[2*ti].add+=lazy[ti].add;
            lazy[2*ti+1].add+=lazy[ti].add;
        }
        
        lazy[ti].add=0;
    }
    
   	if(start>r|| end<l)
    {
        return;
    }
    
    
    if(start>=l && end<=r)
    {
        tree[ti].ss+=(2 * tree[ti].s * val)+ (end-start+1)*val*val;
        tree[ti].s+=(end-start+1)*val;
        
         
        if(start!=end)
        {
            lazy[2*ti].add+=val;
            lazy[2*ti+1].add+=val;
        }
        return;
    }
    
    
    int mid = (start + end)/2;
    addInRange(start, mid, l, r, 2*ti, val);
    addInRange(mid+1, end, l, r, 2*ti+1, val);
    
    tree[ti].s= tree[2*ti].s+tree[2*ti+1].s;
    tree[ti].ss= tree[2*ti].ss+tree[2*ti+1].ss;
}


void updateInRange(int start, int end, int l, int r, int ti, int val)
{
    if(start>end)
        return;
    
    if(start>r|| end<l)
    {
        return;
    }
    
    if(lazy[ti].set!=0)
    {
        tree[ti].ss = (r-l+1)*lazy[ti].set*lazy[ti].set;
        tree[ti].s = (r-l+1)*lazy[ti].set;
        
        if(start!=end)
        {
            lazy[2*ti].set=lazy[ti].set;
            lazy[2*ti+1].set=lazy[ti].set;
            lazy[2*ti].add=0;
            lazy[2*ti+1].add=0;
        }
        
        lazy[ti].set=0;
    }
    
    if(start>=l && end<=r)
    {
        tree[ti].ss= (end-start+1)*val*val;
        tree[ti].s=(end-start+1)*val;
        
         
        if(start!=end)
        {
            lazy[2*ti].set=val;
            lazy[2*ti+1].set=val;
            lazy[2*ti].add=0;
            lazy[2*ti+1].add=0;
            
        }
        return;
    }
    
    
    int mid = (start + end)/2;
    updateInRange(start, mid, l, r, 2*ti, val);
    updateInRange(mid+1, end, l, r, 2*ti+1, val);
    
    tree[ti].s= tree[2*ti].s+tree[2*ti+1].s;
    tree[ti].ss= tree[2*ti].ss+tree[2*ti+1].ss;
    
}

int main() {
  	int t;
	cin>>t;
    
    int count=1;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        cout<<"Case "<<count<<":\n";
        count++;
        
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        for(int i=0;i<4*n;i++)
        {
            lazy[i].set=0;
            lazy[i].add=0;
            tree[i].ss=0;
            tree[i].s=0;
        }
        
        buildTree(0,n-1,1);
        
        while(q--)
        {
            int choice;
            cin>>choice;
            
            if(choice==0)
            {
                int start , end, val;
                cin>>start>>end>>val;
                updateInRange(0,n-1,start-1,end-1,1,val);
            }
            if(choice==1)
            {
                int start , end, val;
                cin>>start>>end>>val;
                addInRange(0,n-1,start-1,end-1,1,val);
            }
            if(choice==2)
            {
                int start, end;
                cin>>start>>end;
                cout<<queryTree(0,n-1, start-1, end-1,1).ss<<"\n";
            }
        }
    }
    
}