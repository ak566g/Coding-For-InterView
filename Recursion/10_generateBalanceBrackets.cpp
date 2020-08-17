#include<bits/stdc++.h>
using namespace std;

void printAllParanthesis(string s, int open, int close, int n)
{

    if(n==close){
        cout<<s<<endl;
        return;
    }
    else{
        if(open>close){
            printAllParanthesis(s+")",open,close+1,n);
        }
        if(open<n){
            printAllParanthesis(s+"(",open+1,close,n);
        }
    }

}


int main()
{
    int n;
    cin>>n;
    printAllParanthesis("",0,0,n);

}
