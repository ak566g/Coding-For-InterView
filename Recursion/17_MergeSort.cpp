#include<bits/stdc++.h>
using namespace std;


void merge(int *a, int start, int mid, int end)
{
    int n1=mid-start+1;
    int n2=end-mid;

    int left[n1];
    int right[n2];

    for(int i=0;i<n1;i++){
        left[i]=a[start+i];
    }

    
    for(int i=0;i<n2;i++){
        right[i]=a[mid+i+1];
    }

    int i=0, j=0, k=start;

    while(i<n1&&j<n2)
    {
        if(left[i]<right[j]){
            a[k++]=left[i++];
        }else{
            a[k++]=right[j++];
        }
    }

    while(i<n1){
        a[k++]=left[i++];
    }

    while(j<n2){
        a[k++]=right[j++];
    }
}


void merge_sort(int *a, int start, int end)
{

    int mid= start +(end-start)/2;
    if(start<end){
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid,end);
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    merge_sort(a,0,n-1);
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

}