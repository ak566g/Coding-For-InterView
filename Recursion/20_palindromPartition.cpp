// Given a string, find all possible palindromic partitions of given string.
// I/P
// nitin
// O/P
// n i t i n
// n iti n
// nitin

#include<bits/stdc++.h>
using namespace std;


bool isPalindrom(string s)
{
    string temp =s;
    reverse(temp.begin(),temp.end());

    return (s==temp);
}

void printAllPalindromPartition(string s, int start, int n, vector<string>&v)
{
    if(s.size()==0)
    {
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<s.size();i++)
    {
        if(isPalindrom(s.substr(0,i+1)))
        {
            v.push_back(s.substr(0,i+1));
            printAllPalindromPartition(s.substr(i+1),i+1,n,v);
            v.pop_back();
        }
    }
}

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    vector<string>v;
    cout<<endl;
    printAllPalindromPartition(s,0,n,v);
}