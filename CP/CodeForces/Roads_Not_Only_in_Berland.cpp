#include <bits/stdc++.h>
using namespace std;

int dsu[1005];

int findSet(int node){
    if(dsu[node]==node){
        return node;
    }

    return dsu[node] = findSet(dsu[node]);
}

void unionSet(int x, int y){
    x = findSet(x);
    y = findSet(y);

    if(x!=y){
        dsu[y] = x;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++){
        dsu[i] = i;
    }
    
    vector<pair<int, int>>list1, list2;

    for(int i=0;i<n-1;i++){
        int x, y;
        cin>>x>>y;

        int a = findSet(x);
        int b = findSet(y);

        if(a==b){
            list1.push_back({x, y});
        }
        else {
            unionSet(x, y);
        }
    }

    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int a = findSet(i);
            int b = findSet(j);

            if(a==b){
                continue;
            }

            list2.push_back({i, j});
            unionSet(i,j);
        }
    }

    cout<<list1.size()<<"\n";

    for(int i=0;i<list1.size();i++){
        cout<<list1[i].first<<" "<<list1[i].second<<" "<<list2[i].first<<" "<<list2[i].second<<"\n";
    }
    return 0;
}