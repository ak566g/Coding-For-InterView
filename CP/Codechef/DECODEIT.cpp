//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    char a[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'};

    while(t--)
    {
        int start = 0, end= 15;
        int len;
        cin>>len;
        string s;
        cin>>s;

        for(int i=0;i<len;i+=4)
        {
            int start = 0, end = 15;
            for(int j=i;j<i+4;j++)
            {
                int mid = (start + end)/2;
                
                if(s[j]=='0')
                {
                    end = mid-1;
                }
                else
                {
                    start = mid+1;
                }
            }

            cout<<a[start];
        }
        cout<<"\n";
    }

}