//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int parent[1000];

int find_set(int a){
    if(parent[a]==a){
        return a;
    }
    return find_set(parent[a]);
}

void union_set(int a, int b){
    a = find_set(a);
    b = find_set(b);

    if(a!=b){
        parent[b]=a;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, e;
    cin>>n>>e;

    for(int i=0;i<=n;i++){
        parent[i]=i;
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