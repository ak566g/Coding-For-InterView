//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

void count(int *a, int *b, int n, int m, int v, unordered_set<int>&s)
{
    if(n==0 || m==0)
    {
        return;
    }

    int v1 = a[0]|v;
    int v2 = v;
    int v3 = b[0]&v;

    s.insert(v1);
    s.insert(v2);
    s.insert(v3);

    count(a+1, b, n-1, m, v1, s);
    count(a, b+1, n, m-1, v3, s);
    count(a+1, b+1, n-1, m-1, v, s);
    count(a+1, b, n-1, m, v3, s);
    count(a, b+1, n, m-1, v1, s);
    count(a+1, b+1, n-1, m-1, v, s);
}

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int *a = new int[n];
        int *b = new int[m];

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }

        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }

        unordered_set<int>s;


        count(a,b,n,m,0,s);
        
        for(auto i: s)
        {
            cout<<i<<" ";
        }
        
        cout<<s.size();
        cout<<endl;
    }
}