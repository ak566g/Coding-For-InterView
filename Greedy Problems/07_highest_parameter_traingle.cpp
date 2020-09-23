//by Ankita Gupta

// Perimeter with conditions
// Aahad gives an array of integers and asks Harshit to find which three elements form a triangle (non-degenerate). The task seems easy to Harshit.
// So, Aahad adds some conditions to this task -
// 1. Find the triangle with maximum perimeter
// 2. If there are two or more combinations with same value of maximum perimeter, then find the one with the longest side.
// 3.If there are more than one combinations which satisfy all the above conditions the find with maximum longest minimum side.

#include<bits/stdc++.h>
using namespace std;

void triangle(int a[], int n)
{
    if(n<3)
    {
        cout<<-1;
        return;
    }
    
    for(int i=0;i<n-2;i++){
       if(a[i]<a[i+1]+a[i+2])
       {
           cout<<a[i+2]<<" "<<a[i+1]<<" "<<a[i];
           return;
       }
    }
    
    cout<<-1;
    return;
}

int main() {

    int n;
    cin>>n;
	
    int a[n];
    
    for(int i=0;i<n;i++)
        cin>>a[i];
    
    sort(a,a+n,greater<int>());
    
    triangle(a,n);
}