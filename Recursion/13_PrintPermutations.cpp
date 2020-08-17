// Given a string S, 
// find and return all the possible permutations of the input string.

#include<bits/stdc++.h>
using namespace std;

void printAllPermutations(string input, string output)
{
    if(input.size()==0){
        cout<<output<<"\n";
        return;
    }

    for(int i=0;i<input.size();i++)
    {
        string temp= input.substr(0,i)+input.substr(i+1);
        char ch= input[i];

        printAllPermutations(temp, output+ch);

    }
}

int main()
{
    string s;
    cin>>s;

    cout<<endl;
    printAllPermutations(s,"");
}