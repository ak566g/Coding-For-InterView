//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
int parent[1000];
int r[1000]; // rank 

int findParent(int a){
    if(parent[a]==a){
        return a;
    }

    return parent[a]=findParent(parent[a]);
}

void union_set(int a, int b){
    a = findParent(a);
    b = findParent(b);

    if(a==b){
        return;
    }

    if(r[a]<r[b]){
        swap(a,b);
    }

    parent[b] = a;
    r[a] += r[b];
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;

    int parent[n+1];

    for(int i=0;i<=n;i++){
        parent[i]=-1;
        r[i]=1;
    }

    for(int i=0;i<e;i++){
        int x, y;
        cin>>x>>y;
        union_set(x, y);
    }

    for(int i=1;i<=n;i++){
        cout<<parent[i]<<" ";
    }
}