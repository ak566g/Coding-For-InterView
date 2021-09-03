//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int cmp(vector<int>a, vector<int>b, vector<int>c){
    int x1 = a[0], y1 = a[1];
    int x2 = b[0], y2 = b[1];
    int x3 = c[0], y3 = c[1];
    
    return (y3 - y2) * (x2 - x1) - (y2 - y1) * (x3 - x2);
}

vector<vector<int>> convexHull(vector<vector<int>>v){
    sort(v.begin(), v.end());
    vector<vector<int>>upper, lower;
    
    for(int i=0;i<v.size();i++){
        while(lower.size() >= 2 && cmp(lower[lower.size()-2], lower[lower.size()-1], v[i]) > 0){
            lower.pop_back();
        }
        lower.push_back(v[i]);
    }

    for(int i=v.size()-1; i>=0 ; i--){
        while(upper.size() >= 2 && cmp(upper[upper.size()-2], upper[upper.size()-1], v[i]) > 0){
            upper.pop_back();
        }
        upper.push_back(v[i]);
    }
    

    set<vector<int>>ans;
    for(auto it : upper)ans.insert(it);
    for(auto it : lower)ans.insert(it);

    vector<vector<int>>result;

    for(auto it : ans)result.push_back(it);

    return result;
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