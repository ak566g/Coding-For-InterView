//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void buildTree(int *a, int start, int end, int *tree, int index)
{
    if(start==end)
    {
        tree[index]=a[start];
        return;
    }

    int mid= (start+end)/2;
    buildTree(a,start,mid,tree,2*index);
    buildTree(a,mid+1,end,tree,2*index+1);

    tree[index]= tree[2*index]+tree[2*index+1];
    return;
}

int main(){
    int n;
    cin>>n;

    int *a = new int[n];

    for(int i=0;i<n;i++)
        cin>>a[i];

    int *tree = new int[2*n];

    buildTree(a,0,n-1,tree,1);

    for(int i=1;i<2*n;i++)
    cout<<tree[i]<<" ";
}