
// Largest number in K swaps 
// Given a number K and string S of digits denoting a positive integer, build the largest number possible by performing swap operations on the digits of S atmost K times.

#include<bits/stdc++.h>
using namespace std;

//Backtracking is used in this solution..

void findMax(string s, string &maxNumber , int k, int start)
{
    if(k==0)
    return;
    
    char ch= s[start];
    int n=s.size();
    for(int i=start;i<n;i++)
    {
        if(ch<s[i])
        {
            ch=s[i];
        }
    }
    
    if(ch!=s[start])
    k--;
    
    for(int i=start;i<n;i++)
    {
        if(s[i]==ch)
        {
            swap(s[i],s[start]);
            if(maxNumber<s)
            maxNumber=s;
            
            findMax(s,maxNumber,k,start+1);
            swap(s[i],s[start]);
        }
    }
}


int main()
 {
	int k;
    cin>>k;
	string s;
	cin>>s;
	string maxNumber=s;
	    
	findMax(s,maxNumber,k,0);
        
    cout<<maxNumber<<"\n";	    
	
	return 0;
}