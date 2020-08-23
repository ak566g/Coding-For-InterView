#include<bits/stdc++.h>
using namespace std;


int find_pivot(int *a,int start,int end){
    int i=start-1;
    int pivot=a[end];
    int j;

    for(j=start;j<=end-1;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
        }
    }

    swap(a[i+1],a[end]);
    return i+1;
    
}

void quick_sort(int *a,int start, int end)
{
    if(start>=end)
    {
        return;
    }

    int pivot= find_pivot(a,start,end);

    quick_sort(a,start,pivot-1);
    quick_sort(a,pivot+1,end);

}


int main()
{
    int n;
    cin>>n;
    int *a= new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    //It has two subroutine...
    //1. split 
    //2. Partitioning 
    quick_sort(a,0, n-1);


    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}