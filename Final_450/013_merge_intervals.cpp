class Solution {
public:
    
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[0]<v2[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector< vector<int> >ans;
        
        ans.push_back(intervals[0]);
        int j=0;
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]>=ans[j][0] && intervals[i][0]<=ans[j][1])
            {
                ans[j][0]=min(intervals[i][0], ans[j][0]);
                ans[j][1]=max(intervals[i][1], ans[j][1]);
            }
            else if(intervals[i][1]>=ans[j][0] && intervals[i][1]<=ans[j][1])
            {
                ans[j][0]=min(intervals[i][0], ans[j][0]);
                ans[j][1]=max(intervals[i][1], ans[j][1]);
            }
            else{
                ans.push_back(intervals[i]);
                j++;
            }
        }
        
        return ans;
    }
};