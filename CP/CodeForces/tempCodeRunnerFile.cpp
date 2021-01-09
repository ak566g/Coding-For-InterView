//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        int *a = new int[n];
        int *contri = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            contri[i]=0;
        }

        int count =0;
        
        for(int i=2;i<n-1;i++)
        {
            if(a[i]>a[i-1] && a[i]>a[i+1])
            {
                count++;
                contri[i-1]++;
                contri[i+1]++;
                contri[i]++;
            }

            else if(a[i]<a[i-1] && a[i]<a[i+1])
            {
                count++;
                contri[i-1]++;
                contri[i+1]++;
                contri[i]++;
            }
        }

        int m = 0;
        int twoCount=0;
        for(int i=0;i<n;i++)
        {
            if(m<contri[i])
            {
                m = contri[i];
            }

            if(m==2)
            {
                twoCount++;
            }
        }

        // cout<<"ans"<<" ";
        if(m>=2)
        {
            cout<<max(0,count-2);
        }
        else if(m==1)
        {
            cout<<max(0,count-1);
        }
        else
        {
            cout<<count;
        }
        
        // cout<<" "<<count<<" "<<m;
        cout<<endl;
    }
}