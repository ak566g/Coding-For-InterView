#include<bits/stdc++.h>
#define maxx 1000001
using namespace std;

vector<int>graph[maxx];
int visited[maxx];
int component[maxx];
int comp;

void clearGraph(){
	comp=0;
	for(int i=0;i<maxx;i++){
		graph[i].clear();
		visited[i]=0;
		component[i]=-1;
	}
}

void dfs(int node){
	visited[node]=true;
	component[node]=comp;

	for(auto child: graph[node]){
		if(visited[child]==false){
			dfs(child);
		}
	}
}

int main(){
	int t;
	cin>>t;

	while(t--){
		int n, m;
		cin>>n>>m;

		vector<pair<int, int>>v;
		
		clearGraph();

		for(int i=0;i<m;i++){
			int x, y;
			string op;

			cin>>x>>op>>y;

			if(op=="="){
				graph[x].push_back(y);
				graph[y].push_back(x);
			}else{
				v.push_back({x,y});
			}
		}			
		for(int i=1;i<=n;i++){
			if(visited[i]==false){
				dfs(i);
				comp++;
				}
		}
		bool ans = true;
		for(int i=0;i<v.size();i++){
			int x = v[i].first;
			int y = v[i].second;
			if(component[x]==component[y]){
				ans=false;
				break;
			}
		}

		if(ans){
			cout<<"YES";
		}else{
			cout<<"NO";
		}
		
		cout<<"\n";
	}
}