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

Lazy lazy[400000];
Tree tree[400000];

void buildTree(int *a, int start, int end, int ti)
{
    if(start==end)
    {
        tree[ti].s=a[start];
        tree[ti].ss=a[start]*a[start];
        return;
    }
    
    int mid= (start+end)/2;
    
    buildTree(a, start, mid, 2*ti);
    buildTree(a, mid+1, end, 2*ti+1);
    
    tree[ti].s=tree[2*ti].s+tree[2*ti+1].s;
    tree[ti].ss=tree[2*ti].ss+tree[2*ti+1].ss;
    
    return;
}

Tree queryTree(int start, int end, int l, int r, int ti)
{
    if(start>end)
    {
        return {0, 0};
    }
    
    
    if(start>r || end<l)
    {
        return {0, 0};
    }
    
    
    if(lazy[ti].set!=0)
    {
        int x= lazy[ti].set;
        tree[ti].ss = (r-l+1)*x*x;
        tree[ti].s= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].set=x;
            lazy[2*ti+1].set=x;
        }
        
        lazy[ti].set=0;
    }
    
    if(lazy[ti].add!=0)
    {
        int x = lazy[ti].add;
        tree[ti].ss+=((r-l+1)*x*x + 2*x*tree[ti].s);
        tree[ti].s+= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].add+=x;
            lazy[2*ti+1].add+=x;
        }
        
        lazy[ti].add=0;
    }
    
    
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start+end)/2;
    
    Tree left = queryTree(start, mid, l, r, 2*ti);
    Tree right = queryTree(mid+1, end, l, r, 2*ti+1);
    
    Tree ans;
    ans.s= left.s+right.s;
    ans.ss= left.ss+right.ss;
    
    return ans;
}

void setValue(int start, int end, int l, int r, int ti, int val)
{
    if(start>end)
    {
        return;
    }
    
    if(lazy[ti].set!=0)
    {
        int x= lazy[ti].set;
        tree[ti].ss = (r-l+1)*x*x;
        tree[ti].s= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].set=x;
            lazy[2*ti+1].set=x;
        }
        
        lazy[ti].set=0;
    }
    
    
    if(lazy[ti].add!=0)
    {
        int x = lazy[ti].add;
        tree[ti].ss+= 2*x*tree[ti].s + (r-l+1)*x*x;
        tree[ti].s+= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].add+=x;
            lazy[2*ti+1].add+=x;
        }
        
        lazy[ti].add=0;
    }
    
    
    if(start>r || end<l)
    {
        return;
    }
    
    if(start>=l && end<=r)
    {
        tree[ti].ss=(end-start+1)*val*val;
        tree[ti].s=(end-start+1)*val;
        z
        if(start!=end)
        {
            lazy[2*ti].set=val;
            lazy[2*ti+1].set=val;
        }
       lazy[ti].set=0;
        return;
    }
    
    int mid = (start+end)/2;
    setValue(start, mid, l, r, 2*ti, val);
    setValue(mid+1, end, l, r, 2*ti+1, val);
    
    tree[ti].s=tree[2*ti].s + tree[2*ti+1].s;
    tree[ti].ss=tree[2*ti].ss + tree[2*ti+1].ss;
    
    return;
}


void addValue(int start, int end, int l, int r, int ti, int val)
{
 	if(start>end)
    {
        return;
    }
    
    
    if(lazy[ti].set!=0)
    {
        int x= lazy[ti].set;
        tree[ti].ss = (r-l+1)*x*x;
        tree[ti].s= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].set=x;
            lazy[2*ti+1].set=x;
        }
        
        lazy[ti].set=0;
    }
    
    if(lazy[ti].add!=0)
    {
        int x = lazy[ti].add;
        tree[ti].ss+=((r-l+1)*x*x + 2*x*tree[ti].s);
        tree[ti].s+= (r-l+1)*x;
        
        if(start!=end)
        {
            lazy[2*ti].add+=x;
            lazy[2*ti+1].add+=x;
        }
        
        lazy[ti].add=0;
    }
    
    
    if(start>r || end<l)
    {
        return;
    }
 
    
    if(start>=l && end<=r)
    {
        tree[ti].ss+= 2*val*tree[ti].s+(end-start+1)*val*val;
        tree[ti].s+=((end-start+1)*val);
        
        if(start!=end)
        {
            lazy[2*ti].add+=val;
            lazy[2*ti+1].add+=val;
        }
        lazy[ti].add=0;
        return;
    }
    
    int mid = (start+end)/2;
    addValue(start, mid, l, r, 2*ti, val);
    addValue(mid+1, end, l, r, 2*ti+1, val);
    
    tree[ti].s=tree[2*ti].s + tree[2*ti+1].s;
    tree[ti].ss=tree[2*ti].ss + tree[2*ti+1].ss;
    
    return;
}

int main() {
	int t;
    cin>>t;
    
    for(int i=1;i<=t;i++)
    {
        cout<<"Case "<<i<<":\n";
        int n, q;
        cin>>n>>q;
        
        int *a = new int[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i];
        
        
        for(int i=0;i<4*n;i++)
        {
            lazy[i].add=0;
            lazy[i].set=0;
        }
        
        buildTree(a,0,n-1,1);
        
        while(q--)
        {
            int option;
            cin>>option;
            
            if(option==0)
            {
                int l, r, x;
                cin>>l>>r>>x;
                
                setValue(0,n-1,l-1,r-1,1,x);
            }
            
            else if(option==1)
            {
                int l, r, x;
                cin>>l>>r>>x;
                
                addValue(0,n-1,l-1,r-1,1,x);
            }
            else if(option==2)
            {
                int l, r;
                cin>>l>>r;
                
                cout<<queryTree(0,n-1,l-1,r-1,1).ss<<"\n";
            }
        }
    }
}