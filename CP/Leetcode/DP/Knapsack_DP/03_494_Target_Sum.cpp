class Solution {
public:
    int subsetSum(vector<int> v,int sum,int n)
    {
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                dp[i][j]=0;
                else if(j==0)
                dp[i][j]=1;
            }
        }
        
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(v[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-v[i-1]] + dp[i-1][j];
                }
                else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[n][sum];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        long sumarr=0;
        
        for(int i=0;i<nums.size();i++)
            sumarr+=nums[i];
        if(sumarr<target)
            return 0;
        
        if((sumarr+target)%2)
            return 0;
        
        int sum = (target + sumarr)/2;
        
        int ans = subsetSum(nums,sum,nums.size());
        return ans;
    }
};

