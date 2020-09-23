//by Ankita Gupta
//Question Link
//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room/0

#include<bits/stdc++.h>
using namespace std;

class Activity{
    public:
        int start;
        int end;
        int index;
};

bool cmp(Activity & a1, Activity & a2)
{
    return a1.end<a2.end;
}

int main() {
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    Activity a[n];
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i].start;
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i].end;
	        a[i].index=i+1;
	    }
	   
	    sort(a, a+n, cmp);
	    
	    cout<<a[0].index<<" ";
	    
	    int j=0;
	    for(int i=1;i<n;i++)
	    {
	        if(a[i].start>=a[j].end)
	        {
	            cout<<a[i].index<<" ";
	            j=i;
	        }
	    }
	    cout<<endl;
	    
	}
	
	return 0;
}