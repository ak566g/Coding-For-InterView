#include<iostream>
#include<cstring>
using namespace std;


void multiply(ull a[2][2], ull m[2][2])
{
    ull first = ((a[0][0]*m[0][0])%mod+(a[0][1]*m[1][0])%mod)%mod;
    ull second = ((a[0][0]*m[0][1])%mod+(a[0][1]*m[1][1])%mod)%mod;
    ull third = ((a[1][0]*m[0][0])%mod+(a[1][1]*m[1][0])%mod)%mod;
    ull fourth = ((a[1][0]*m[0][1])%mod+(a[1][1]*m[1][1])%mod)%mod;
    a[0][0]=first;
    a[0][1]=second;
    a[1][0]=third;
    a[1][1]=fourth;
}

void findFib(ull a[2][2], ull n)
{
    if(n==0||n==1)
    {
    	return;    
    }
    
    
    findFib(a,n/2);
    
    multiply(a,a);
    
    if(n%2==1)
    {
    	ull m[2][2]={{1,1},{1,0}};    
        multiply(a,m);
    }
}

ull findSum(ull first, ull second, ull total)
{
    ull sum=(first+second)%mod;
    ull next = (first+second)%mod;
    
    for(ull i=2;i<total;i++)
    {
        sum+=next;
        first= second;
        second=next;
        next = (first+second)%mod;
    }
    return sum%mod;
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
    
//     if(m==0)
//     {
//         ull total= n-m+1;
//     	ull sum = findSum(0, 1, total);
//     	return sum;
//     }
    
//     ull A[2][2]={{1,1},{1,0}};
// 	findFib(A,m-1);
// 	ull first = A[0][0];
//     ull B[2][2]={{1,1},{1,0}};
//     findFib(B,m);
//     ull second = B[0][0];
//     // cout<<first<<" "<<second;
//     // cout<<endl;
    
//     ull total= n-m+1;
//     ull sum = findSum(first, second, total);
    
  
	ull A[2][2]={{1,1},{1,0}};
	findFib(A,n+1);
	ull first = A[0][0];
    ull B[2][2]={{1,1},{1,0}};
	findFib(B,m);
    ull second = B[0][0];
    
    // if u are subtracting in mod, please add it once, for avoiding wrong tcs.
    return (first-second + mod)%mod;
    
    // return sum;
}

int main()
{
    unsigned long long m,n;
    cin>>m>>n;
	cout<<fiboSum(m,n);
    return 0;
}

