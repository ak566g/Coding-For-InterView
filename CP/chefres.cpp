#include <bits/stdc++.h>
#define ppi pair<int , int>
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    vector<ppi>v;
	    
	    for(int i=0;i<m;i++){
	        int x,y;
	        cin>>x>>y;
	        v.push_back({x,y});
	    }
	    
	    sort(v.begin(),v.end());
	    
	    while(n--)
	    {
	        int x;
	        cin>>x;
	        
	        int it= lower_bound(v.begin(),v.end(),make_pair(x,0))-v.begin();
	        
	       // cout<<it<<"\n";
	       
	       if(it==0)
	       {
	           cout<<v[0].first-x<<"\n";
	       }
	       else
	       {
	           if(v[it-1].second>x)
	           cout<<0<<"\n";
	           else if(it<m)
	           {
	               cout<<v[it].first-x<<"\n";
	           }
	           else
	           {
	               cout<<-1<<"\n";
	           }
	           
	       }
	    }
	    
	}
	
	return 0;
}
