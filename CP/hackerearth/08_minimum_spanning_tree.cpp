#include<bits/stdc++.h>
using namespace std;

class edge{
	public:
		int x, y, w;
};

bool cmp(edge e1 , edge e2){
	return e1.w<e2.w;
}

vector<edge>v;
int parent[10001];

int find_set(int a){
	if(parent[a]<0){
		return a;
	}

	return parent[a] = find_set(parent[a]);
}

void union_set(int a, int b){
	parent[b]=a;
}

int main(){
	int n, e;
	cin>>n>>e;

	for(int i=0;i<=n;i++){
		parent[i]=-1;
	}

	for(int i=0;i<e;i++){
		edge e;
		cin>>e.x>>e.y>>e.w;

		v.push_back(e);
	}

	sort(v.begin(), v.end(), cmp);
	int mst = 0;

	for(int i=0;i<e;i++){
		int a = v[i].x;
		int b = v[i].y;

		a = find_set(a);
		b = find_set(b);

		if(a!=b){
			mst += v[i].w;
			union_set(a, b);
		}
	}

	cout<<mst;
}