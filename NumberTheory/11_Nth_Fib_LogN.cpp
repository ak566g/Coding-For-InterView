//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void multiply(int a[2][2], int m[2][2])
{
    int first = (a[0][0]*m[0][0]) +(a[0][1]*m[1][0]) ;
    int second =(a[0][0]*m[0][1]) +(a[0][1]*m[1][1]) ;
    int third = (a[1][0]*m[0][0]) +(a[1][1]*m[1][0]) ;
    int fourth =(a[1][0]*m[0][1]) +(a[1][1]*m[1][1]) ;
    a[0][0]=first;
    a[0][1]=second;
    a[1][0]=third;
    a[1][1]=fourth;

}

void findFib(int a[2][2], int n)
{
    if(n==0||n==1)
    {
        return;
    }

    findFib(a,n/2);

    multiply(a,a);

    if(n%2==1)
    {
        int m[2][2]={{1,1},{1,0}};    
        multiply(a,m);
    }
}

int nthFib(int n)
{
    int a[2][2]={{1,1},{1,0}};

    findFib(a,n-1);
    return a[0][0];
}


int main(){
    int n;
    cin>>n;

    cout<<nthFib(n);
}