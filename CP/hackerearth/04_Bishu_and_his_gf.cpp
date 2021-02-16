#include<bits/stdc++.h>
using namespace std;

vector<int>graph[10001];
int dist[10001];
bool visited[10001];
vector<int>gc;

void dfs(int s){
	visited[s]=true;
	for(auto x:graph[s]){
		if(visited[x]==false){
			dist[x]=dist[s]+1;
			dfs(x);
		}
	}
}

int girlfriend(int n){

	dist[0]=0;
	dist[1]=0;

	dfs(1);

	int d=INT_MAX, ans=0;
	
	sort(gc.begin(), gc.end());

	for(int i=0;i<gc.size();i++){
		if(dist[gc[i]]<d){
			d=dist[gc[i]];
			ans=gc[i];
		}
	}

	return ans;
}


int main()
{
	int v;
	cin>>v;

	for(int i=0;i<v-1;i++){
		int x, y;
		cin>>x>>y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int q;
	cin>>q;

	while(q--){
		int x;
		cin>>x;
		gc.push_back(x);
	}

	memset(visited, false, sizeof(visited));
	cout<<girlfriend(v);
}