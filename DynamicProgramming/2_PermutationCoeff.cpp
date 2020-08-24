//by Ankita Gupta
// Permutation refers to the process of arranging all the members of a given set to form a sequence. 
// The number of permutations on a set of n elements is given by n! , where “!” represents factorial.
// The Permutation Coefficient represented by P(n, k) is used to represent the number of ways to obtain an ordered subset having k elements from a set of n elements.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, r;
    cin>>n>>r;
    int ans=1;
    for(int i=n-r;i<=n;i++)
    {
        ans*=i;
    }
    cout<<ans;
}