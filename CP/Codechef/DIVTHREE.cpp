//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n, k, d;
        cin>>n>>k>>d;

        int *a = new int[n];
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;

            sum += x;
        }

        cout<<min(sum/k, d)<<"\n";

    }
}