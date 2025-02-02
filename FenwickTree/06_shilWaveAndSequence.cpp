// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-wave-seqeuncemonk/

// There is nothin in a catterpillar that tells you its going to be a butterfly ------------------- !
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define mod 1000000007
ll bt[100011][2]={0};
ll a[100011];
ll bt1[100011]={0};
void update(int ind ,ll val,int pos){
	while(ind<=100000){
		bt[ind][pos]+=val;
		bt[ind][pos]%=mod;
		ind+=(ind&-ind);
	}
}
ll query(int ind,int pos){
	ll ans=0;
	while(ind>0){
		ans+=bt[ind][pos];
		ans%=mod;
		ind-=(ind&-ind);
	}
	return ans;
}
void update1(int ind ,ll val){
	while(ind<=100000){
		bt1[ind]+=val;
		ind+=(ind&-ind);
	}
}
ll query1(int ind){
	ll ans=0;
	while(ind>0){
		ans+=bt1[ind];
		ind-=(ind&-ind);
	}
	return ans;
}

int main(){
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> a[i+1];
	}
	ll ans=0;
	ll f,s;
	for(int i=1;i<=N;i++){
		
		f=query(a[i]-1,1);
		s=query(100000,0)-query(a[i],0);
		s+=mod;
		s%=mod;
		f+=query1(a[i]-1);
		s=s+query1(100000)-query1(a[i]);
		
		f%=mod;
		s%=mod;
		
		update1(a[i],1);
		update(a[i],f,0);
		update(a[i],s,1);
		
		ans=ans+f+s;
		ans%=mod;
		
	}
	cout<<ans;
}