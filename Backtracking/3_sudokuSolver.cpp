
// Sudoku solver Leetcode..

class Solution {
public:
    
    bool isSafeRow(vector<vector<int>>&board, int row, int col, int num)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[row][i]==num)
                return false;
        }
        
        return true;
    }
    
    bool isSafeCol(vector<vector<int>>&board, int row, int col, int num)
    {
        for(int i=0;i<board.size();i++)
        {
            if(board[i][col]==num)
                return false;
        }
        
        return true;
    }
    
    bool isSafeGrid(vector<vector<int>>&board, int row, int col, int num)
    {
        int rowFactor= row- (row%3);
        int colFactor= col- (col%3);
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[i+rowFactor][j+colFactor]==num)
                    return false;
            }
        }
        
        return true;
    }
    
    bool isSafe(vector<vector<int>>&board, int row, int col, int num)
    {
        
        bool ans1=isSafeRow(board,row,col,num);
        bool ans2=isSafeCol(board,row,col,num);
        bool ans3=isSafeGrid(board,row,col,num);
        
        if(ans1&&ans2&&ans3)
            return true;
        
        return false;
    }
    
    
    bool findEmptyLocation(vector<vector<int>>&board, int &row, int &col)
    {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[i].size();j++)
            {
                if(board[i][j]==0)
                {
                    row=i;
                    col=j;
                    return true;
                }
            }
        }
        
        return false;
    }
    

    bool helper(vector<vector<int>>&board)
    {
        int row,col;
        
        if(!findEmptyLocation(board,row,col))
            return true;
        
        for(int i=1;i<=9;i++)
        {
            if(isSafe(board,row,col,i))
            {
                board[row][col]=i;
                if(helper(board))
                    return true;
                board[row][col]=0;
            }
        }
        return false;
    }
   
    
    
    
    void solveSudoku(vector<vector<char>>& b) {
        vector<vector<int>>board;
        
        for(int i=0;i<b.size();i++){
            vector<int>v;
            for(int j=0;j<b[i].size();j++){
                if(b[i][j]=='.')
                    v.push_back(0);
                else
                    v.push_back(b[i][j]-'0');
            }
            board.push_back(v);
        }
        
        
        helper(board);
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board.size();j++){
                char ch=board[i][j]+'0';
                b[i][j]=ch;
            }
        }
    }
};