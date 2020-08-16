// Problem Statement
// k       1 2 3 4 5 6 7 8 9 10..........
// n= 1    0
// n= 2    0 1
// n= 3    0 1 1 0
// n= 4    0 1 1 0 1 0 0 1
// n= 5    0 1 1 0 1 0 0 1 1 0 0 1 0 1 1 0
// For each next line 0 will converted into 0 1 and 1 will converted into 1 0
// n and k will be given , return value at n,k.

#include<bits/stdc++.h>
using namespace std;


int kth_symbol(int n, int k){
    if(n==1&&k==1){
        return 0;
    }

    int mid= pow(2,n-1)/2;

    if(k<=mid){
        return kth_symbol(n-1,k);
    }else{
        return !kth_symbol(n-1,k-mid);
    }

}

int main()
{
    int n, k;
    cin>>n>>k;
    cout<<kth_symbol(n,k);
}

