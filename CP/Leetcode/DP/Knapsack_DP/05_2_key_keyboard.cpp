class Solution {
public:
    
    set<pair<int,int>>visited;
    
    int helper(int cur, int total ,int n){
        if(total>n){
            return 100000;
        }
        
        if(total==n){
            return 0;
        }
        
        if(visited.count({cur,total})>0){
            return 100000;
        }else{
            visited.insert({cur, total});
        }
        
        int ans1 = 1+helper(total,total, n); // copy
        int ans2 = 1+helper(cur,total+cur, n); //paste
        return min(ans1, ans2);
    }
    
    int minSteps(int n) {
        visited.clear();
        return n==1?0:helper(1, 0, n);
    }
};