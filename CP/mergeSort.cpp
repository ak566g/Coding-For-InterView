#include<bits/stdc++.h>
using namespace std;


void merge(int *a, int start, int mid, int end){

    int n1=mid-start+1;
    int n2=end-mid;

    int *left = new int [n1];
    int *right = new int[n2];

    for(int i=0;i<n1;i++){
        left[i]=a[i+start];
    }

    for(int i=0;i<n2;i++){
        right[i]=a[i+mid+1];
    }

    int i=0,j=0,k=start;

    while(i<n1&&j<2){
        if(left[i]<right[j])
        {
            a[k]=left[i];
            i++;
        }else{
            a[k]=right[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k]=left[i];
        i++;
        k++;
    }

    while(j<n2){
        a[k]=right[j];
        k++;
        j++;
    }
  
}

void merge_sort(int *a, int start, int end)
{
    if(start>=end){
        return;
    }

    int mid=start+(end-start)/2;
    merge_sort(a,start,mid);
    merge_sort(a,mid+1,end);
    merge(a,start,mid,end);
}

int main(){
    int n;
    cin>>n;
    int *a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    merge_sort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}