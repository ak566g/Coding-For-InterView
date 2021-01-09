//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void reverse(int *a, int l, int r)
{
    while(l<r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}

void merge(int *a, int l, int mid, int r)
{
    int i = l;
    int j = mid+1;
    while(i<=mid && a[i]<0)
    {
        i++;
    }

    while(j<= r && a[j]<0)
    {
        j++;
    }

    reverse(a, i, mid);
    reverse(a, mid+1, j-1);

    reverse(a, i, j-1);
}


void seg(int *a, int l, int r)
{
    if(l>=r)
    {
        return;
    }

    int mid = l + (r-l)/2;

    seg(a, l, mid);
    seg(a, mid+1, r);

    merge(a, l, mid, r);
}

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int *a = new int[n];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }       

        seg(a, 0, n-1);

        
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }       

        cout<<endl;
    }
}