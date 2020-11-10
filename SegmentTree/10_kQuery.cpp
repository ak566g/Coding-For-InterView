// https://www.spoj.com/problems/KQUERY/

//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<int>tree[30001];

vector<int> merge(vector<int>v1, vector<int>v2)
{
    vector<int>ans;
    int m=v1.size(), n=v2.size();
    int i=0, j=0;
    while(i<m && j<n)
    {
        if(v1[i]<=v2[j])
        {
            ans.push_back(v1[i]);
            i++;
        }
        else
        {
            ans.push_back(v2[j]);
            j++;
        }
    }

    while(i<m)
    {
        ans.push_back(v1[i]);
        i++;
    }

    while(j<n)
    {
        ans.push_back(v2[j]);
        j++;
    }

    return ans;
}

void buildTree(int *a , int si, int ei, int ti)
{
    if(si==ei)
    {
        tree[ti].push_back(a[si]);
        return;
    }

    int mid = (si+ei)/2;
    buildTree(a, si, mid, 2*ti);
    buildTree(a, mid+1, ei, 2*ti+1);
    
    tree[ti] = merge(tree[2*ti], tree[2*ti+1]);
}

int queryTree(int si, int ei, int qs, int qe, int val, int ti)
{
    if(si > ei)
    {
        return 0;
    }

    if(qs>ei || qe<si)
    {
        return 0;
    }

    if(si>=qs && ei<=qe)
    {
        int count =tree[ti].end() -upper_bound(tree[ti].begin(), tree[ti].end(), val);
        return count;
    }
    int mid = (si+ei)/2;
    int left = queryTree(si, mid, qs, qe, val, 2*ti);
    int right = queryTree(mid+1, ei, qs, qe, val, 2*ti+1);
    return left+right;

}


int main(){
    int n;
    cin>>n;

    int *a = new int[n+1];

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    buildTree(a, 1, n, 1);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        int start, end, val;
        cin>>start>>end>>val;
        cout<<queryTree(1, n, start, end, val , 1)<<"\n";
    }

}