class Solution {
public:
    
    int dp[366];
    
    int helper(bool days[], int cur, vector<int>&costs){
        if(cur>=366){
            return 0;
        }
        
        if(dp[cur]!=-1){
            return dp[cur];
        }
        
        if(days[cur]==true){
            int ans1 = costs[0] + helper(days, cur+1, costs);
            int ans2 = costs[1] + helper(days, cur+7, costs);
            int ans3 = costs[2] + helper(days, cur+30, costs);
            return dp[cur] = min(ans1,min(ans2, ans3));
        }
        
        return dp[cur] = helper(days, cur+1, costs);
    }
    
    int mincostTickets(vector<int>& d, vector<int>& costs) {
        bool days[366];
        memset(days, false, sizeof(days));
        memset(dp, -1, sizeof(dp));
        
        for(int i=0;i<d.size();i++){
            days[d[i]]=true;
        }
        
        return helper(days, 1, costs);
    }
};