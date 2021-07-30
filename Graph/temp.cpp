#include <bits/stdc++.h>

using namespace std;

#define ll long long
vector<vector<ll>> merge(vector<vector<ll>>& iv) {
        sort(iv.begin(), iv.end());
        vector<vector<ll>>ans;
        vector<ll>cur = iv[0];
        
        for(int i=1;i<iv.size();i++){
            ll x1 = cur[0], y1 = cur[1];
            ll x2 = iv[i][0], y2 = iv[i][1];
            
            if(max(x1, x2) <= min(y1, y2)){
                cur[0] = min(x1, x2);
                cur[1] = max(y1, y2);
            }else{
                ans.push_back(cur);
                cur = iv[i];
            }
        }
        
        ans.push_back(cur);
        return ans;
}


bool solution(vector<int>&A, vector<int>&P, int B, int E){

    int n = P.size();
    vector<vector<ll>>iv;

    for(int i=0;i<n;i++){
        ll l = P[i] - A[i];
        ll r = P[i] + A[i];
        l = l<0?0 : l;

        iv.push_back({l, r});
    }

    
    iv = merge(iv);
    
    if(B>E){
        swap(B,E);
    }

    for(int i=0;i<iv.size();i++){
        if(iv[i][0]<=B && iv[i][1]>=E)return true;
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, b, e;
    cin>>n>>b>>e;
    vector<int>A(n), P(n);

    for(int i=0;i<n;i++){
        cin>>A[i];
    }

    for(int i=0;i<n;i++){
        cin>>P[i];
    }


    cout<<solution(A, P, b, e);

    return 0;
}
