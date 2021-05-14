class Solution {
public:
    
    static bool cmp(vector<int>&v1, vector<int>&v2){
        return v1[1]<v2[1];
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), cmp);
        int ans = 1;
        int start = 0;
        int p = 1;
        
        while(p<pairs.size() && start<pairs.size()){
            if(pairs[start][1]<pairs[p][0]){
                ans++;
                start = p;
            }
            p+=1;
        }
        
        return ans;
    }
};