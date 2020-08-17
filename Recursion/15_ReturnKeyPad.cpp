// Given an integer n, using phone keypad find out and 
// print all the possible strings that can be made using digits of input n.

#include<bits/stdc++.h>
using namespace std;

string keypad[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void printAllKeypad(int n, string output)
{   
    if(n==0){
        cout<<output<<"\n";
        return;
    }

    int digit= n%10;
    
    for(int i=0;i<keypad[digit].size();i++)
    {
        printAllKeypad(n/10,keypad[digit][i]+output);
    }
}   

int main()
{
    int n;
    cin>>n;

    printAllKeypad(n, "");
}