#include<bits/stdc++.h>
using namespace std;

void TOH(int n, string a, string b)
{
    if(n==1){
        cout<<n<<" "<<a<<" "<<b<<"\n";
        return ;
    }

    TOH(n-1, b, a);
    cout<<n<<" "<<a<<" "<<b<<"\n";
    TOH(n-1, a, b);
    // cout<<n<<" "<<a<<" "<<b<<"\n";
}


int main()
{
    int n;
    cin>>n;
    string a="source", b="hepler";
    TOH(n,a,b);
}