//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;

    while(t--)
    {
        int n, m;
        cin>>n>>m;

        int *a = new int[n];
        int *b = new int[m];

        int asum=0;
        int bsum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            asum+=a[i];
        }

        for(int i=0;i<m;i++)
        {
            cin>>b[i];
            bsum+=b[i];
        }

        sort(a, a+n);
        sort(b,b+m, greater<int>());

        int swap=0;
        int i=0, j=0;
        while(asum<=bsum && i<n && j<m)
        {
            swap+=1;
            int x = a[i];
            int y = b[j];

            asum -= x;
            asum += y;

            bsum += x;
            bsum -= y;
            
            i+=1;
            j+=1;
        }

        if(asum>bsum)
        cout<<swap<<"\n";
        else
        {
            cout<<-1<<"\n";
        }
        
    }

}