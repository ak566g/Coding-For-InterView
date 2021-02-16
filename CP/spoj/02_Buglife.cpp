//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2001];
bool visited[2001];
bool color[2001];

bool suspecious(int s, bool c){
    visited[s]=true;
    color[s]=c;

    for(auto x: graph[s]){
        if(visited[x]==false){
            bool ans = suspecious(x, c^1);
            if(ans==false){
                return false;
            }
        }
        else{
            if(color[s]==color[x]){
                return false;
            }
        }
    }

    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    for(int tc=1;tc<=t;tc++){
        
        int v, e;
        cin>>v>>e;

        for(int j=0;j<=2000;j++){
            graph[j].clear();
            color[j]=0;
            visited[j]=0;
        }

        for(int j=1;j<=e;j++){
            int x, y;
            cin>>x>>y;
            graph[x].push_back(y);
            graph[y].push_back(x);        
        }

        bool ans = true;

        for(int j=1;j<=v;j++){
            if(visited[j]==false){
                bool temp = suspecious(j, 0);

                if(temp==false){
                    ans=false;
                }
            }
        }
        cout<<"Scenario #"<<tc<<":\n";
        if(ans){
            cout<<"No suspicious bugs found!";
        }
        else{
            cout<<"Suspicious bugs found!";
        }
        cout<<"\n";
    }
}