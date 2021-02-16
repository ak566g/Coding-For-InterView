//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
bool visited[10001];

void dfs(int s)
{
    visited[s]=true;

    for(auto x:graph[s]){
        if(visited[x]==false){
            dfs(x);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int v, e;
    cin>>v>>e;

    if(e!=v-1){
        cout<<"NO";
        return 0;
    }

    for(int i=0;i<e;i++){
        int x, y;
        cin>>x>>y;

        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
    dfs(1);


    for(int i=1;i<=v;i++){
        if(visited[i]==false){
            cout<<"NO";
            return 0;
        }
    }

    cout<<"YES";
    return 0;
}