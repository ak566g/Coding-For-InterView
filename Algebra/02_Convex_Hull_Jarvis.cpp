//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int orientation(vector<int>p1, vector<int>p2, vector<int>p3){
    int x1 = p1[0], y1 = p1[1];
    int x2 = p2[0], y2 = p2[1];
    int x3 = p3[0], y3 = p3[1];

    return (y2 - y1)*(x3 - x2) - (y3 - y2)*(x2 - x1);

}

bool bw(vector<int>p1, vector<int>p2, vector<int>p3){
    bool x = (p2[0] >= p1[0] && p2[0] <= p2[0]) || (p2[0] <= p1[0] && p2[0] >= p3[0]);
    bool y = (p2[1] >= p1[1] && p2[1] <= p2[1]) || (p2[1] <= p1[1] && p2[1] >= p3[1]);

    return x&&y;
}


vector<vector<int>> convexHull(vector<vector<int>>v){
    int n = v.size();
    if(n <= 3){
        return v;
    }

    vector<vector<int>>hull;

    int l = 0;

    for(int i=1;i<n;i++){
        if(v[i][0] < v[l][0]) l = i;
    }

    int p = l, q;

    do{
        q = (p+1)%n;
        for(int i=0;i<n;i++){
            if(orientation(v[p], v[i], v[q]) < 0) q=i;
        }

        for(int i=0;i<n;i++){
            if(i!=p && i!=q && orientation(v[p], v[i], v[q]) == 0 && bw(v[p], v[i], v[q])){
                hull.push_back(v[i]);
            }
        }
        hull.push_back(v[q]);
        p = q;
    }while(p!=l);

    return hull;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<vector<int>>p;
    int n;
    cin>>n;

    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        p.push_back({x,y});
    }

    vector<vector<int>>ans = convexHull(p);

    for(int i=0;i<ans.size();i++){
        cout<<ans[i][0]<<" "<<ans[i][1]<<"\n";
    }
}