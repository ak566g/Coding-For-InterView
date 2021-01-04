//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int findIndex(int *a, int n)
{
    int index = 0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>a[index])
        index=i;
    }
    return index;
}

int findIndexMin(int *a, int n)
{
    int index = 0;

    for(int i=0;i<n;i++)
    {
        if(a[i]<a[index])
        index=i;
    }
    return index;
}


int main(){
    int n, p, q;
    cin>>n>>p>>q;

    int *a = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    int count = 0;

    bool sub = true;
    while(sub)
    {
        count++;
        int index;
        if(p>=q)
        {
            index = findIndex(a,n);
        }
        else
        {
            index = findIndexMin(a,n);
        }
        

        for(int i=0;i<n;i++)
        {
            if(i==index)
            {
                a[i]-=p;
            }
            else
            {
                a[i]-=q;
            }
        }
        bool temp=false;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                temp=true;
            }
        }

        if(!temp)
        {
            sub = false;
        }

    }

    cout<<count;
}