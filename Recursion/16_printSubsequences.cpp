// Given a string print all subsequences of it

#include<bits/stdc++.h>
using namespace std;

void printSubsequences(string s, string output)
{
    if(s.size()==0){
        cout<<output<<endl;
        return;
    }

    printSubsequences(s.substr(1),output+s[0]);
    printSubsequences(s.substr(1),output);
}

int main()
{
    string s;
    cin>>s;
    cout<<endl;
    printSubsequences(s,"");
}
