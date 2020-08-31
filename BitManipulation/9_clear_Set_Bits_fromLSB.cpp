//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int clearedLSB(int n, int i)
{
    int mask=1<<(i+1);
    mask=mask-1;
    mask = ~mask;

    return n&mask;

}

// Example

// 1 0 0 0 1 1 1 1 
// i= 3

// mask should be 
// 1 1 1 1 1 0 0 0

// 1<<(i+1)

// 0 0 0 0 1 0 0 0

// 1<<(i+1)-1

// 0 0 0 0 0 1 1 1

// ~(1<<(i+1)-1)

// 1 1 1 1 1 0 0 0

// Now doing and will generate correct answer



int main(){
    int n,i;
    cin>>n>>i;

    cout<<clearedLSB(n,i);
}