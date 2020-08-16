#include<bits/stdc++.h>
using namespace std;


void printAllSubset(int *a, int n, int *output, int size)
{
    if(n==0){
        for(int i=0;i<size;i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return ;
    }

    printAllSubset(a+1, n-1, output, size);
    int *smallOutput = new int[size+1];

    for(int i=0;i<size;i++){
        smallOutput[i]=output[i];
    }
    smalloutput[size]=a[0];

    printAllSubset(a+1,n-1,smallOutput,size+1);

}


void printAllSubset(int *a, int n)
{
    int *output= new int[n];
    printAllSubset(a,n, output,0);
}


int main()
{
    int n;
    cin>>n;

    int *a= new int[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    printAllSubset(a,n);
}