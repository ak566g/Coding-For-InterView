class Solution {
public:  
    int minTaps(int n, vector<int>& ranges) {
        int dp[n+1];
        
        for(int i=0;i<=n;i++){
            dp[i]=10000;
        }
        
        dp[0]=0;
        
        for(int i=0;i<=n;i++){
            int left = max(0, i-ranges[i]);
            int right = min(n, i+ranges[i]);
            
            for(int j=left;j<=right;j++){
                dp[j]=min(dp[j], dp[left]+1);
            }
        }
        
        if(dp[n]==10000){
            return -1;
        }
        
        return dp[n];
    }
};