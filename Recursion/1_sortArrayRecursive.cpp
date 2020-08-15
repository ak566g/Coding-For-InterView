#include<bits/stdc++.h>
using namespace std;

void insert(int *a, int n, int temp){
    
    if(n==0||(a[n-1]<=temp)){
        a[n]=temp;
        return ;
    }

    int val = a[n-1];
    insert(a, n-1, temp);
    a[n]=val;

}


void sort_recursive(int *a, int n){

    if(n==1)
        return;

    int temp = a[n-1];
    sort_recursive(a,n-1);

    insert(a,n-1,temp);
} 


int main()
{
    int n;
    cin>>n;


    int *a = new int[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort_recursive(a, n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}