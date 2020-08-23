#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int n, m;
	cin>>n>>m;
	
	ll *a= new ll[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	int count_m=0;
	queue<ll>q;
	int endp=n-1;
	sort(a,a+n);
	while(m--){
		int cur_m;
		cin>>cur_m;
		ll ans;
		for(;count_m<cur_m;count_m++){
			if(endp>=0&&(q.size()==0||a[endp]>q.front())){
				ans=a[endp];
				endp--;
			}else{
				ans=q.front();
				q.pop();
			}
			
			q.push(ans/2);
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
}
