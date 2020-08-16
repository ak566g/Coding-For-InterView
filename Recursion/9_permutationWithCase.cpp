#include<bits/stdc++.h>
using namespace std;


void permutations(string s, string output)
{
    if(s.size()==0){
        cout<<output<<"\n";
        return;
    }

    output+=toupper(s[0]);
    permutations(s.substr(1),output); 
    output.pop_back();
    output+=tolower(s[0]);
    permutations(s.substr(1),output);
}

int main()
{
    string s;
    cin>>s;

    permutations(s,"");
}