//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool graph[1001][1001];
int d1[]={1,-1, 0, 0};
int d2[]={0, 0, 1, -1};


bool isValid(int x, int y, int m, int n){
    return (x>=1 && x<=m && y>=1 && y<=n && graph[x][y]);
}

void dfs(int x, int y, int m, int n){
    graph[x][y]=0;

    for(int i=0;i<4;i++){
        if(isValid(x+d1[i], y+d2[i], m, n)){
            dfs(x+d1[i], y+d2[i], m, n);
        }
    }
}

int countRooms(int m, int n){
    int count = 0;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(graph[i][j]){
                dfs(i, j, m, n);
                count++;
            }
        }
    }
    return count;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;
    cin>>m>>n;

    memset(graph, 0, sizeof(graph));

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char c;
            cin>>c;
            if(c=='.'){
                graph[i][j]=true;
            }
        }
    }

    cout<<countRooms(m, n);

}