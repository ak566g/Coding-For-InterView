class Solution {
public:
    
    long dp[101][101][101];
    int mod = pow(10,9)+7;
    
    int helper(vector<int>&p, vector<int>&g, int ci, int mem, int minProfit){
        
        if(mem<0){
            return 0;
        }
        
        if(ci>g.size()){
            return 0;
        }
        
        if(ci==g.size()){
            if(0>=minProfit){
                return 1;
            }
            return 0;
        }
        
        if(dp[ci][mem][minProfit]!=-1){
            return dp[ci][mem][minProfit];
        }
        
        long ans1 = helper(p, g, ci+1, mem-g[ci], max(0, minProfit-p[ci]))%mod;
        long ans2= helper(p, g, ci+1, mem, minProfit)%mod;
        
        return dp[ci][mem][minProfit] = (ans1+ans2)%mod;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp, -1, sizeof(dp));
        return helper(profit, group, 0, n, minProfit);
    }
};