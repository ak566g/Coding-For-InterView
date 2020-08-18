
#include<bits/stdc++.h>
using namespace std;

int gray(int n)
{
    if(n==0){
        return 0;
    }

    int a= n%10;
    int b= (n/10)%10;

    if(a!=b)
    {
        return (1+10*gray(n/10));
    }else
    {
        return 10*gray(n/10);
    }
    

}

int main()
{
    int n;
    cin>>n;

    cout<<gray(n);   
}