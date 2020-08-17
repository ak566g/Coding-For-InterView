// Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. 
// You are given a numeric string S. 
// Write a program to print the list of all possible codes that can be generated from the given string.

// Input format :
// A numeric string S
// Output Format :
// All possible codes in different lines

// Sample Input:
// 1123
// Sample Output:
// aabc
// kbc
// alc
// aaw
// kw

#include<bits/stdc++.h>
using namespace std;

char alphabets[27];

void printAllCodes(string input, string output)
{
    if(input.size()==0)
    {
        cout<<output<<"\n";
        return;
    }

    int number1=(input[0]-'0');

    if(number1>=0&&number1<=9)
    {
        printAllCodes(input.substr(1),output+alphabets[number1]);
    }

    
    if(input.size()>1){
        int number2=input[1]-'0';
        int number = number1*10 + number2;

        if(number>=10&&number<=26){
            printAllCodes(input.substr(2),output+alphabets[number]);
        }
    }


}

void init()
{
    for(int i=1;i<=26;i++){
        alphabets[i]=(char)('A'+i-1);
    }
}


int main()
{
    string s;
    cin>>s;
    init();
    cout<<endl;

    printAllCodes(s,"");
}