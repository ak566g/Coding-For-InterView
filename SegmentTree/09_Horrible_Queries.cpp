
// Horrible Queries

// World is getting more evil and it's getting tougher to get into the Evil League of Evil. 
// Since the legendary Bad Horse has retired, 
// now you have to correctly answer the evil questions of Dr. Horrible, who has a PhD in horribleness (but not in Computer Science). 
// You are given an array of N elements, which are initially all 0. After that you will be given C commands. 
// They are -

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void updateTree(ll *tree, ll *lazy, int start, int end, int l, int r, ll val, int ti)
{
    if(start>end)
        return;
    
    if(lazy[ti]!=0)
    {
        tree[ti]+=lazy[ti]*(end-start+1);
        if(start!=end)
        {
            lazy[2*ti]+=lazy[ti];
            lazy[2*ti+1]+=lazy[ti];
        }
        lazy[ti]=0;
    }
    
    if(start>r || end<l)
        return;
    
    if(start>=l && end <= r)
    {
        tree[ti]+=val*(end-start+1);
        
        if(start!=end)
        {
            lazy[ti*2]+=val;
            lazy[ti*2 + 1]+=val;
        }
        return;
    }
    
    int mid = (start + end)/2;
    
    updateTree(tree, lazy, start , mid, l, r, val, 2*ti);
    updateTree(tree, lazy, mid+1 , end, l, r, val, 2*ti+1);
    tree[ti]=tree[2*ti]+tree[2*ti+1];
}

ll queryTree(ll *tree, ll *lazy, int start, int end, int l, int r, int ti)
{
    if(start>end)
        return 0;
    
    
    
    if(lazy[ti]!=0)
    {
        tree[ti]+=lazy[ti]*(end-start+1);
        if(start!=end)
        {
            lazy[2*ti]+=lazy[ti];
            lazy[2*ti+1]+=lazy[ti];
        }
        lazy[ti]=0;
    }
    
    if(start>r || end<l)
        return 0;
    
    if(start>=l && end<=r)
        return tree[ti];
    
    int mid= (start+end)/2;
    
    ll left=queryTree(tree, lazy, start, mid, l, r, 2*ti);
    ll right=queryTree(tree, lazy, mid+1, end, l, r, 2*ti+1);
    
    return left+right;
}

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;


        ll *tree= new ll[3*n];
        ll *lazy= new ll[3*n];

        for(int i=0;i<3*n;i++)
        {
            tree[i]=0;
            lazy[i]=0;
        }

        int q;
        cin>>q;

        while(q--)
        {
            int option;
            cin>>option;

            if(option==0)
            {
                int l, r;
                ll v;
                cin>>l>>r>>v;
                updateTree(tree, lazy, 0, n-1, l-1, r-1, v, 1);
            }

            else if(option==1)
            {
                int l, r;
                cin>>l>>r;

                cout<<queryTree(tree, lazy, 0,n-1, l-1, r-1, 1)<<"\n";
            }
        }
    }
}