#include<bits/stdc++.h>
using namespace std;

int segragate(int *a, int n)
{
    int pivot=0;
    int i=-1;

    for(int j=0;j<=n-1;j++){
        if(a[j]<pivot)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    return i;
}

void arrange(int *a, int n, int p)
{
    int i=0, j=p;

    while(j<n&&i<n)
    {
        if((i%2==1)&&(a[i]<0))
        {
            int temp=a[j];

            for(int k=j;k>=i;k--){
                a[k]=a[k-1];
            }
            a[i]=temp;
            i++;
            j++;
        }
        else
        {
            i++;
        }
        
    }
}

int main()
{
    int n;
    n=10;
    int a[10]={-5,-2,5,2,4,7,1,8,0,-8};
    // cin>>n;
    // int *a=new int[n];

    int i= segragate(a, n);

     for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }

    arrange(a,n,i+1);
    cout<<endl;
    for(int j=0;j<n;j++){
        cout<<a[j]<<" ";
    }
}