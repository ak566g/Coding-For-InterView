class Solution {
public:
    int lenLongestFibSubseq(vector<int>& a) {
        int n = a.size();
        
        if(n==1 || n==2)return 0;
        
        int ans = 2;
        int dp[n][n];
        
        unordered_map<int, int>mp;
        for(int i=0;i<n;i++)mp[a[i]]=i;
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(i==j)dp[i][j]=1;
                else
                    dp[i][j]=2;
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int k = a[i]+a[j];
                if(mp.count(k)>0){
                    dp[j][mp[k]] = dp[i][j]+1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        
        return ans==2?0:ans;
    }
};