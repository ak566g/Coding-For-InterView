#include<iostream>
#include<bits/stdc++.h> 
#define ll long long
using namespace std;

ll fact[21];

void init(){
    memset(fact, 0, sizeof(fact));
    fact[0]=1;
    fact[1]=1;

    for(ll i=1;i<=21;i++){
        fact[i]=fact[i-1]*i;
    }
}

int GetArrangements(string s)
{
    ll total = fact[s.size()];
    map<char, int>mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }
    ll div=1;

    for(auto i:mp){
        div*=i.second;
    }

    return total/div;
}

int main()
{
	string s;
	cin>>s;
    init();
	cout<<GetArrangements(s);
	return 0;
    
}