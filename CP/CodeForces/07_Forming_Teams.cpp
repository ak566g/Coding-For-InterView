//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[101];
set<int>a;
set<int>b;
set<int>c;



void create_set(int n){
    for(int i=1;i<=n;i++){
        int root = i;
        int child1 = -1;
        int child2 = -1;

        if(graph[i].size()==2){
            child1=graph[i][0];
            child2=graph[i][1];
        }else if(graph[i].size()==1){
            child1=graph[i][0];
        }

        

    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m, n;
    cin>>n>>m;

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    create_set(n);
}