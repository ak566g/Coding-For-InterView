//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int inDegree[10001];
vector<int>graph[10001];

vector<int> topsort(int n){
    priority_queue<int, vector<int>, greater<int>>pq;
    vector<int>ans;

    for(int i=1;i<=n;i++){
        if(inDegree[i]==0){
            pq.push(i);
        }   
    }

    while(!pq.empty()){
        int cur = pq.top();
        pq.pop();
        ans.push_back(cur);

        for(auto node : graph[cur]){
            inDegree[node]--;

            if(inDegree[node]==0){
                pq.push(node);
            }
        }
    } 

    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;

    memset(inDegree, 0, sizeof(inDegree));

    for(int i=0;i<m;i++){
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        inDegree[y]++;
    }

    vector<int>ans = topsort(n);

    if(ans.size()==n){
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
    else{
        cout<<"Sandro fails.";
    }
}