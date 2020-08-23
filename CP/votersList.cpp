#include<bits/stdc++.h>
using namespace std;

int main(){
	int n1, n2, n3;
	cin>>n1>>n2>>n3;
	int n=n1+n2+n3;
	int *a= new int[n];
	
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	vector<int>v;
	sort(a,a+n);
	
	for(int i=0;i<n;){
		int j=i;
		int count=0;
		while(j<n&&(a[j]==a[i])){
			j++;
			count++;
		}
		if(count>=2){
			v.push_back(a[i]);
		}
		i=j;
	}
	
	cout<<v.size()<<"\n";
	
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<"\n";
	}
}
