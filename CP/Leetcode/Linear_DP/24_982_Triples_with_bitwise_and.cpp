class Solution {
public:
    int countTriplets(vector<int>& A) {
        int ans = 0;
        int n = A.size();
        unordered_map<int, int>um;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                um[A[i]&A[j]]++;
            }
        }
        
        for(auto it : um){
            for(int i=0;i<n;i++){
                if((it.first&A[i])==0){
                    ans += it.second;
                }
            }
        }
        
        return ans;
    }
};