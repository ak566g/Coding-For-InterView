class Solution {
public:
    
    int helper(int *arr, int n){
        stack<int>st;
        int left[n], right[n];
        left[0]=0;
        right[n-1]=n-1;
        st.push(0);
        
        for(int i=1;i<n;i++){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i] = 0;
            }else{
                left[i] = st.top()+1;
            }
            st.push(i);
        }
        
        while(!st.empty())st.pop();
        
        st.push(n-1);
        
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                st.pop();
            }
            
            if(st.empty()){
                right[i]=n-1;
            }else{
                right[i]=st.top()-1;
            }
            st.push(i);
        }
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans, (right[i]-left[i]+1)*arr[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0){
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        
        int mat[m][n];
        
        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = matrix[i][j] - '0';
            }
            
            ans = max(ans, helper(mat[i], n));
        }
        
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]!=0){
                    mat[i][j] += mat[i-1][j];
                }
            }
            ans = max(ans, helper(mat[i], n));
        }
        
        return ans;
    }
};