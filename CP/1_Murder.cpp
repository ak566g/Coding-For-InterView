// Once detective Saikat was solving a murder case. 
// While going to the crime scene he took the stairs and saw that a number is written on every stair. 
// He found it suspicious and decides to remember all the numbers that he has seen till now. 
// While remembering the numbers he found that he can find some pattern in those numbers. 
// So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. 
// Calculate the sum of all the numbers written on his notes diary.
// Answer may not fit in integer . You have to take long

//This question is variation of inversion count..

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll merge(ll *a, int start, int mid, int end)
{
    int n1=mid-start+1;
    int n2=end-mid;
    
    ll left[n1];
    ll right[n2];
    ll rightSum=0;
    
    for(int i=0;i<n1;i++)
        left[i]=a[start+i];
    
    for(int i=0;i<n2;i++)
        right[i]=a[mid+i+1];
    
    int i=0, j=0, k=start;
    ll totalSum=0;
    while(i<n1&&j<n2)
    {
        if(left[i]<right[j])
        {
            a[k]=left[i];
            totalSum+=(left[i]*(n2-j));
            i++;
        }
        else
        {
            a[k]=right[j];
            j++;
        }
        k++;
    }
    
    while(i<n1)
    {
        a[k]=left[i];
        i++;
        k++;
    }
    
    while(j<n2)
    {
        a[k]=right[j];
        j++;
        k++;
    }
    
    return totalSum;
}


ll murder(ll *a, int start, int end)
{
    if(start<end)
    {
        int mid = start + (end-start)/2;
       	ll leftAns=murder(a,start,mid);
        ll rightAns=murder(a,mid+1,end);
    	ll mergeAns=merge(a,start,mid,end);
        return leftAns+mergeAns+rightAns;
    }
    
    return 0;
}


int main() {

	// Write your code here
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
    	    
        cout<<murder(a,0,n-1)<<"\n";
        
//         for(int i=0;i<n;i++)
//             cout<<a[i];
    	
    }
    
}