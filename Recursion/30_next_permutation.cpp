//Implement Next permutation function
//Use of stl is not allowed

#include<bits/stdc++.h>
using namespace std;


void reverse_array(int *a, int start, int end)
{
    while(start<end)
    {
        int temp=a[start];
        a[start]=a[end];
        a[end]=temp;
        start++;
        end--;
    }
    return;
}

void nextPermuatation(int *a, int n)
{
    int i=n-2;

    while(i>=0&&a[i+1]<=a[i])
    {
        --i;
    }

    if(i==-1)
    {
        reverse_array(a,0,n-1);
        return;
    }


    for(int j=n-1;j>i;j++)
    {
        if(a[j]>a[i])
        {
            swap(a[j],a[i]);
            break;
        }
        
    }
    
    reverse_array(a,i+1,n-1);
    
    return;

}


int main()
{
    int n;
    cin>>n;

    int *a = new int [n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    nextPermuatation(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}