#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10000];
bool visited[10000];
int dist[10000];
int level[10000];

void resetData(){
	for(int i=0;i<10000;i++){
		dist[i]=-1;
		visited[i]=0;
		level[i]=0;
	}
}

void bfs(int node){
	queue<int>q;
	q.push(node);
	visited[node]=1;
	dist[node]=0;

	while(!q.empty()){
		int curr = q.front();
		q.pop();

		for(auto child: graph[curr]){
			if(visited[child]==false){
				visited[child]=true;
				dist[child] = dist[curr]+1;
				q.push(child);
				level[dist[child]]++;
			}
		}
	}

}

int main(){
	int n, m;
	cin>>n>>m;

	for(int i=0;i<m;i++){
		int x, y;
		cin>>x>>y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	int q;
	cin>>q;

	while(q--){
		int x, y;
		cin>>x>>y;
		resetData();
		bfs(x);

		cout<<level[y]<<"\n";
	}
}