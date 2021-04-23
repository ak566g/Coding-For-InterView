// giving tle
// -------------------------------------------------------------------------
// class Solution {
// public:
//     long long dp[1005][1005];
//     int mod = pow(10, 9) + 7;
//     int helper(vector<string>& words, int curx, int ti, string &target){
        
//         if(target.size()>words[0].size()){
//             return 0;
//         }
        
//         if(dp[curx][ti]!=-1){
//             return dp[curx][ti];
//         }
        
//         if(ti>target.size()){
//             return dp[curx][ti] = 0;
//         }
//         if(ti==target.size()){
//             return dp[curx][ti] = 1;
//         }
        
//         int ans = 0;
//         for(int i=0; i<words.size(); i++){
//             for(int j= curx; j<words[i].size();j++){
//                 char ch = words[i][j];
//                 if(ch == target[ti]){
//                     ans = (ans + helper(words, j+1, ti+1, target))%mod;
//                 }
//             }
//         }
        
//         return dp[curx][ti] = ans%mod;
//     }
    
//     int numWays(vector<string>& words, string target) {
//         memset(dp, -1, sizeof(dp));
//         return helper(words, 0, 0, target);
//     }
// };


// accepted code
#define ll long long
// example of map
// ["acca","bbbb","caca"]
//      0   1   2   3 
//  a   1   1   0   2      
//  b   1   1   1   1
//  c   1   1   2   0
//  d   0   0   0   0


class Solution {
public:
    int mp[1005][257];      // map of char on particular index.
    int dp[1005][1005];
    int mod = 1000000007;
    int n;                  // length of current string.
    
    ll helper(int cx, int tx, int ti, string &target){
        
        if(tx >= ti){
            return 1;
        }
        
        if(cx>=n){
            return 0;
        }
        
        
        if(dp[cx][tx]!=-1){
            return dp[cx][tx];
        }
        
        ll ans1 = helper(cx+1, tx, ti, target)%mod;
        ll ans2 = 0;
        
        if(mp[cx][target[tx]]!=0){
            ans2= (mp[cx][target[tx]]*helper(cx+1, tx+1, ti, target))%mod;
        }
        return dp[cx][tx] = (ans1+ans2)%mod;
    }
    
    int numWays(vector<string>& words, string target) {
        memset(mp, 0, sizeof(mp));
        memset(dp, -1, sizeof(dp));
        
        n = words[0].size();
        
        for(auto w:words){
            for(int i=0;i<w.size();i++){
                mp[i][w[i]]++;
            }
        }
        
        return helper(0, 0, target.size(), target);
    }
};