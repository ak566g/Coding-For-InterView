//by Ankita Gupta

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int findMin(vector<int> &v, int i){
    int curIndex = i;
    for(int idx = i+1; idx < v.size(); idx++){
        if(v[idx] <= v[curIndex]){
            curIndex = idx;
        }
    }

    return curIndex;
}

void solve(vector<int> &v){
    vector<vector<int>>ans;
    int curI = 0;
    while(curI < v.size()){
        int ni = findMin(v, curI);
        if(curI == ni)break;
        reverse(v.begin()+curI, v.begin()+ni+1);
        ans.push_back({curI+1, ni+1, 1});
        curI++;
    }

    cout<<ans.size()<<"\n";
    for(auto it : ans){
        cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<"\n";
    }

    // for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);

        for(int i=0;i<n;i++)cin>>v[i];

        solve(v);
    }
}