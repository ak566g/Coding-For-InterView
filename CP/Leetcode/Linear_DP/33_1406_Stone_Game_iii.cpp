class Solution {
public:
    
    // if both play optimally, and alice starting first, alice will try to maximize his score
    // and bob will try to minimize alice's score
    // in below code, if p==0 it means alice is playing and p == 1 means bob is playing
    
    int dp[50000][2];
    
    int helper(vector<int>& stone, int cur, int n, int p){
        if(cur>=n){
            return 0;
        }
        
        if(dp[cur][p]!=-1){
            return dp[cur][p];
        }
        
        if(p==0){
            int ans1=INT_MIN;
            int ans2=INT_MIN;
            int ans3=INT_MIN;
            
            if(cur<n){
                ans1 = stone[cur] + helper(stone, cur+1, n, 1-p);
            }
            
            if(cur+1<n){
                ans2 = stone[cur] + stone[cur+1] + helper(stone, cur+2, n, 1-p);
            }
            
            if(cur+2<n){
                ans3 = stone[cur] + stone[cur+1] + stone[cur+2] + helper(stone, cur+3, n, 1-p);
            }
            
            return dp[cur][p] = max(ans1, max(ans2, ans3));
        }
        
        
        int ans1 = helper(stone, cur+1, n, 1-p);
        int ans2 = helper(stone, cur+2, n, 1-p);
        int ans3 = helper(stone, cur+3, n, 1-p);
        
        return dp[cur][p] = min(ans1, min(ans2, ans3));
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        
        memset(dp, -1, sizeof(dp));
        
        int n = stoneValue.size();
        int total = 0;
        
        for(int i=0;i<n;i++){
            total+=stoneValue[i];
        }
        
        int alice = helper(stoneValue, 0, n, 0);
        int bob = total - alice;
        
        if(bob==alice){
            return "Tie";
        }
        
        if(bob>alice){
            return "Bob";
        }
        
        return "Alice";
    }
};