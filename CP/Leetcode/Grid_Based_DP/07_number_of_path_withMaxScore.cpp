#define pi pair<long long, long long>
class Solution {
public:
    pi dp[105][105];
    int mod = pow(10, 9)+7;
    
    int toChar(char ch){
        return ch-'0';
    }
    
    pi helper(vector<string>& board, int x, int y){
        
        if(x<0 || y<0){
            return {0, 0};
        }
        
        if(board[x][y]=='E'){
            return {0, 1};
        }
        
        if(board[x][y] == 'X'){
            return {0, 0};
        }
        
        
        if(dp[x][y].first!=-1){
            return dp[x][y];
        }
        
        int ch = toChar(board[x][y]);
        
        if(board[x][y]=='S'){
            ch = 0;
        }
        
        pi ans1 = helper(board, x-1, y-1);
        pi ans2 = helper(board, x, y-1);
        pi ans3 = helper(board, x-1, y);
        
        long long sum = 0;
        sum = max(ans1.first, max(ans2.first, ans3.first));
        
        long long count = 0;
        if(ans1.first==sum){
            count=(count+ans1.second)%mod;
        }
        if(ans2.first==sum){
            count=(count+ans2.second)%mod;
        }
        if(ans3.first==sum){
            count=(count+ans3.second)%mod;
        }
        
        return dp[x][y] = {sum+ch, count};
    }
    
    
    vector<int> pathsWithMaxScore(vector<string>& board) {
        
        for(int i=0;i<=101;i++){
            for(int j=0;j<=101;j++){
                dp[i][j]={-1,-1};
            }
        }
        
        pair<int, int>p = helper(board, board.size()-1, board[0].size()-1);
        if(p.second == 0){
            return {0, 0};
        }
        return {p.first, p.second};
    }
};