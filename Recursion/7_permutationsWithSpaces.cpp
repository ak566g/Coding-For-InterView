// A string wiil be given
// add spaces to all possible permutations
// string abc
// o/p 
// a bc
// ab c
// a b c


#include<bits/stdc++.h>
using namespace std;


void printAllPermutaionOfSpaces(string input, string output)
{
    if(input.size()==0){
        cout<<output<<"\n";
        return;
    }

    string out1=output+" "+input[0];
    string out2=output+input[0];
    printAllPermutaionOfSpaces(input.substr(1),out1);
    printAllPermutaionOfSpaces(input.substr(1),out2);
}

int main()
{
    string s;
    cin>>s;

    string output="";
    output+=s[0];

    printAllPermutaionOfSpaces(s.substr(1),output);
}