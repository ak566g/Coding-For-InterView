
//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int *findLPS(char T[])
{
    int n=strlen(T);
    int *lps = new int[n];
    int i=1, j=0;
    lps[0]=0;
    
    while(i<n)
    {
        if(T[i]==T[j])
        {
            lps[i]=j+1;
            i++;
            j++;
        }
        else if(j==0)
        {
            lps[i]=0;
            i++;
        }
        else {
            j=lps[j-1];
        }
    }
    
    return lps;
}

int findString(char S[], char T[]) {

    int *lps=findLPS(T);
    //int start = -1;
    int i=0, j=0;
    
    int n=strlen(S), m=strlen(T);
    
    while(i<n && j<m)
    {
        if(S[i]==T[j])
        {
            i++;
            j++;
        }
        else if(j==0)
        {
            i++;
        }
        else {
            j=lps[j-1];
        }
        
        if(j==m)
        {
            return i-m;
        }
    }
    
    return -1;
}

int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}