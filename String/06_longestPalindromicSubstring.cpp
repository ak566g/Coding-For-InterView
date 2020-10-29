//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int countPalindromeSubstrings(char s[]) {
	int n=strlen(s);
    int count=0;
    
    for(int i=0;i<n;i++)
    {
        int l=i, r=i;
        
        while(l>=0 && r<n && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        
        l=i;
        r=l+1;
        
         while(l>=0 && r<n && s[l]==s[r])
        {
            count++;
            l--;
            r++;
        }
        
    }
    
    return count;
	
}

int main() {
    char input[10000];
    cin >> input;
    cout << countPalindromeSubstrings(input) << endl;
}
