class Solution {
public:
    vector<int> countBits(int num) {
        
        if(num==0){
            return {0};
        }
        
        vector<int>ans(num+1, 0);
        ans[0]=0;
        ans[1]=1;
        
        for(int i=2;i<=num;i++){
            ans[i]=ans[i/2];
            
            if(i%2==1){
                ans[i]+=1;
            }
        }
        
        return ans;
    }
};