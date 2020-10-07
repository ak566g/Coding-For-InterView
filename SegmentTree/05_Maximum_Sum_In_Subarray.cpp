//by Ankita Gupta

// Maximum Sum In Subarray

// You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
// Given M queries, your program must output the results of these queries.

#include<bits/stdc++.h>
#define INF -100000
using namespace std;
class Tree{
  	public:
    int prefix;
    int suffix;
    int sum;
    int maxsum;
};


Tree compare (Tree t1, Tree t2)
{
    Tree ans;
    ans.prefix = max(t1.prefix, t1.sum+t2.prefix);
    ans.suffix = max(t2.suffix, t1.suffix+t2.sum);
    ans.sum = t1.sum+t2.sum;
    ans.maxsum = max(t1.maxsum, max(t2.maxsum, t1.suffix+t2.prefix));
    
    return ans;
}

void buildTree(int *a, Tree *tree, int start, int end, int ti)
{
    if(start==end)
    {
        tree[ti].prefix=a[start];
        tree[ti].suffix=a[start];
        tree[ti].sum=a[start];
        tree[ti].maxsum=a[start];
        return;
    }
    
    int mid = (start + end)/2;
    
    buildTree(a, tree, start, mid, 2*ti);
    buildTree(a, tree, mid+1, end, 2*ti+1);
    
    tree[ti]= compare(tree[2*ti], tree[2*ti+1]);
    
    return;
}

Tree queryTree(Tree *tree, int start, int end, int l, int r, int ti)
{
    if(start>end)
    {
        return {INF, INF, INF, INF};
    }
    
    if(start>r || end<l)
    {
        return {INF, INF, INF, INF};
    }
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    int mid = (start+end)/2;
    
    Tree left = queryTree(tree, start, mid, l, r, 2*ti);
    Tree right = queryTree(tree, mid+1, end, l, r, 2*ti+1);
    
    Tree ans= compare(left, right);
    
    return ans;
}


int main() {
	int n;
    cin>>n;
    
    int *a = new int[n];
    
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    
    Tree *tree= new Tree[4*n];
    buildTree(a, tree, 0, n-1, 1);
    
    int q;
    cin>>q;
    
    while(q--)
    {
        int l, r;
        cin>>l>>r;
        
        cout<<queryTree(tree, 0, n-1, l-1, r-1, 1).maxsum<<"\n";
    }
}