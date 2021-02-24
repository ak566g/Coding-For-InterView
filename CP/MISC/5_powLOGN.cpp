//by Ankita Gupta

#include<iostream>
using namespace std;

int power(int n, unsigned int x)
{
    if(x==0)
        return 1;
    
    if(x%2==0){
        return power(n,x/2)*power(n,x/2);
    }
    else
    {
        return n*power(n,x/2)*power(n,x/2);
    }
}

int main() {
	// Write your code here
	
    int n,x;
    cin>>n>>x;
    cout<<power(n,x);
}
