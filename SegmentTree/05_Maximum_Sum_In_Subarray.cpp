//by Ankita Gupta

// Maximum Sum In Subarray

// You are given a sequence A[1], A[2], ..., A[N] . ( |A[i]| ≤ 15007 , 1 ≤ N ≤ 50000 ). A query is defined as follows:
// Query(x,y) = Max { a[i]+a[i+1]+...+a[j] ; x ≤ i ≤ j ≤ y }.
// Given M queries, your program must output the results of these queries.

#include<bits/stdc++.h>
using namespace std;

class Tree{
    public:
    int prefix;
    int suffix;
    int sum;
    int maxSum;
};

void buildTree(int *a, int start, int end, Tree *tree, int ti)
{
    if(start==end)
    {
        tree[ti].sum=a[start];
        tree[ti].prefix=a[start];
        tree[ti].suffix=a[start];
        tree[ti].maxSum=a[start];
        return;
    }
    
    int mid= (start + end)/2;
	
    buildTree(a, start, mid, tree, 2*ti);
    buildTree(a, mid+1, end, tree, 2*ti+1);
    
    Tree left = tree[2*ti];
    Tree right = tree[2*ti+1];
    
   	tree[ti].prefix= max(left.prefix, left.sum+right.prefix);
    tree[ti].suffix= max(right.suffix, right.sum+left.suffix);
    tree[ti].sum = left.sum+ right.sum;
    //tree[ti].maxSum =max(left.maxSum, max(right.maxSum, max(left.sum+right.prefix,max(right.sum+left.suffix, left.suffix+right.prefix))));
    tree[ti].maxSum = max(left.maxSum, max(right.maxSum, left.suffix + right.prefix));
    
    return;
}


Tree queryTree(Tree *tree, int start , int end, int l, int r, int ti)
{
    if(r<start || l>end)
    {
        Tree ans;
        ans.prefix=-100000; // INT_MIN will not work here because of integer overflow :(
        
        ans.suffix=-100000;
        ans.sum=-100000;
        ans.maxSum=-100000;
        return ans;
    }
    
    
    if(start>=l && end<=r)
    {
        return tree[ti];
    }
    
    
    int mid= (start + end)/2;
    
    Tree left = queryTree(tree, start, mid, l, r, 2*ti);
    Tree right = queryTree(tree, mid+1, end, l, r, 2*ti +1);
    
    Tree ans;
    ans.prefix= max(left.prefix, left.sum+right.prefix);
    ans.suffix= max(right.suffix, right.sum+left.suffix);
    ans.sum = left.sum+ right.sum;
    //ans.maxSum = max(left.maxSum, max(right.maxSum, max(left.sum+right.prefix,max(right.sum+left.suffix, left.suffix+right.prefix))));
    ans.maxSum= max(left.maxSum, max(right.maxSum, left.suffix + right.prefix));
    
    return ans;
 	   
}

int main() {

	int n;
    cin>>n;
    
    int *a = new int[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    Tree *tree = new Tree[4*n];
    
    buildTree(a,0,n-1,tree,1);
    
    int q;
    cin>>q;
    
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        l--;
        r--;
        cout<<queryTree(tree, 0, n-1, l, r, 1).maxSum<<"\n";
    }
}