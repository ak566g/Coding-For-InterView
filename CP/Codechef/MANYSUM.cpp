//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        unsigned long long n, ans, l, r;
        cin>>l>>r;

        unordered_set<int>s;

        for(int i=l;i<=r;i++)
        {
            for(int j=l;j<=r;j++)
            {
                s.insert(i+j);
            }
        }

        cout<<s.size()<<"\n";
    }
}