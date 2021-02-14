#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1000];
bool visited[1000];

void dfs(int s){
	visited[s]=true;

	for(auto i:graph[s]){
		if(visited[i]==false){
			dfs(i);
		}
	}
}

int connectedComponents(int n, int e){
	int count = 0;
	
	for(int i=1;i<=n;i++){
		if(visited[i]==false){
			count++;
			dfs(i);
		}
	}
	return count;
}

int main()
{
	int n, e;
	cin>>n>>e;

	for(int i=0;i<e;i++){
		int x, y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	memset(visited, false, sizeof(visited));
	cout<<connectedComponents(n, e);
	
}