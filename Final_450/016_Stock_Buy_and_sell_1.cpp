// Basic idea is to find min of left array from current index and subtract it 
// with element of current index and find maximum difference.

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int leftmin = prices[0];
        
        for(int i=1;i<prices.size();i++){
            ans = max(prices[i]-leftmin, ans);
            leftmin = min(leftmin, prices[i]);
        }
        return ans;
    }
};