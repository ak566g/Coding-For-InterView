class Solution {
public:
    
    
    int combination(int n, int r){
        int ans =1 ;
        
        for(int i=1;i<=r;i++){
            ans = ans * (n-i+1)/i;
        }
        
        return ans;
    }
   
    string kthSmallestPath(vector<int>& dst, int k) {
        int h = dst[1];
        int v = dst[0];
        int n = h+v;
        string ans = "";
        
        for(int i=0;i<n;i++){
            if(h){
                int c = combination(h-1+v, v);
                if(c>=k){
                    ans += 'H';
                    h--;
                }
                else{
                    ans += 'V';
                    k-=c;
                    v--;
                }
            }else{
                ans += 'V';
                v--;
            }
        }
        
        
        return ans;
    }
};