#include<bits/stdc++.h>
using namespace std;


int find_pivot(int *a, int start, int end)
{
    int element=a[end];

    int i=start-1;

    for(int j=start;j<=end-1;j++){
        if(a[j]<element){
            i++;
            swap(a[j],a[i]);
        }
    }
    i++;
    swap(a[i],a[end]);
    return i;

}


void quick_sort(int *a, int start, int end)
{
    if(start>=end)
    return;

    int pivot= find_pivot(a,start,end);
    quick_sort(a,start,pivot-1);
    quick_sort(a,pivot+1,end);
}


int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    quick_sort(a,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}