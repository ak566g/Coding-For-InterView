class Solution {
public:
    
    int dp[50001];
    
    class Job{
        public:
            int s, e, p;
    };
    
    static bool cmp(Job &j1, Job &j2){
        return j1.e > j2.e;
    }
    
    int helper(Job *job, int n, int cur){
        if(cur>=n){
            return 0;
        }
        
        if(dp[cur]!=-1){
            return dp[cur];
        }
        
        // finding nearest possible position
        int j = cur+1;
        while(j<n && job[cur].s < job[j].e){
            j++;
        }
        
        return dp[cur] = max(job[cur].p + helper(job, n, j), helper(job, n, cur+1));
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        memset(dp, -1, sizeof(dp));
        
        int n = startTime.size();
        Job *job = new Job[n];
        
        for(int i=0;i<n;i++){
            job[i].s = startTime[i];
            job[i].e = endTime[i];
            job[i].p = profit[i];
        }
        sort(job, job+n, cmp);
        return helper(job, n, 0);
    }
};