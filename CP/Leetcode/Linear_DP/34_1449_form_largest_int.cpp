
// variation of unbounded knapsack.

class Solution {
public:
    
    string dp[10][5001];
    
    string helper(vector<int>&cost, int target, int cur, int n){
        if(cur>=n || target<0){
            return "0";
        }
        
        if(target==0){
            return "";
        }
        
        if(dp[cur][target]!=""){
            return dp[cur][target];
        }
        
        char ch = cur+'1';
        string ans1 = helper(cost, target-cost[cur], cur, n);
        if(ans1!="0"){
            ans1+=ch;
        }
        string ans2 = helper(cost, target, cur+1, n);
        
        
        if(ans1.size()==ans2.size()){
            return dp[cur][target] = max(ans1, ans2);
        }
        else if(ans1.size()>ans2.size()){
            return dp[cur][target] = ans1;
        }
        return dp[cur][target] = ans2;
    }
    
    string largestNumber(vector<int>& cost, int target) {
        for(int i=0;i<9;i++){
            for(int j=0;j<=5000;j++){
                dp[i][j]="";
            }
        }
        return helper(cost, target, 0, cost.size());
    }
};