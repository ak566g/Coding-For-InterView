#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int n= s.size();

		map<int,vector<int>>m;

		for(int i=0;i<n;i++){
			m[s[i]].push_back(i);
		}

		// for(auto i:m){
		// 	vector<int>v=i.second;

		// 	for(int j=0;j<v.size();j++){
		// 		cout<<v[j]<<" ";
		// 	}
		// 	cout<<endl;

		// }

		int oddcount=0;
		for(auto i : m){
			if(i.second.size()%2==1){
				oddcount++;
			}
		}

		if(oddcount>=2){
			cout<<-1<<endl;
			continue;
		}

		int *a= new int[n];
		int start=0, end=n-1;	
		for(auto i : m){
			vector <int>v= i.second;
			int step=0;
			if(v.size()%2==1){
				a[n/2]=v[step];
				step++;
			}
			
			for(int j=step;j<v.size();j+=2){
				a[start]=v[j];
				a[end]=v[j+1];
				start++;
				end--;
			}
			
		}

		for(int i=0;i<n;i++){
			cout<<a[i]+1<<" ";
		}

		cout<<endl;

	}
}
