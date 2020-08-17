// Count ways to express a number as sum of powers
// Given two integers x and n, we need to find number of ways to express x as sum of n-th powers of unique natural numbers. 
// It is given that 1 <= n <= 20.

#include<bits/stdc++.h>
using namespace std;


//n is given number, k is the power and i is for including or not including number
int numberOfWays(int n, int k, int i)
{
    int num=(n-(pow(i,k)));

    if(num==0)
    return 1;

    else if(num<0)
    return 0;

    else
    return numberOfWays(num,k,i+1)+numberOfWays(n,k,i+1);

}

int main()
{
    int n,k;
    cin>>n>>k;
    
    cout<<numberOfWays(n,k,1);   
}
