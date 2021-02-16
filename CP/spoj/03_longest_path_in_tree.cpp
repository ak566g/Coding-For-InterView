//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int visited[10001];



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;

    for(int i=0;i<e;i++){
        int x, y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
}