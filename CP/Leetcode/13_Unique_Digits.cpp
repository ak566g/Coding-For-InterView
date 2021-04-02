class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        
        if(n==0){
            return 1;
        }
        
        int dp[n+1];
        dp[0]=1;
        dp[1]=9;
        
        for(int i=2;i<=n;i++){
            dp[i]=(dp[i-1]*(10-i+1));
        }
        
        for(int i=1;i<=n;i++){
            dp[i]+=dp[i-1];
        }
        
        return dp[n];
    }
};