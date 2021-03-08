//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[50001];
bool visited[50001];
int out[50001];

void clearDS(){
    memset(visited, 0, sizeof(visited));
    memset(out, 0, sizeof(out));

    for(int i=0;i<=50001;i++){
        graph[i].clear();
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int n, m;
        cin>>n>>m;
        clearDS();

        for(int i=0;i<m;i++){
            int x, y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }
        
    }
}