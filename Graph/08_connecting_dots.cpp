//by Ankita Gupta

// Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). 
// Now Gary is getting bore and wants to play a game. 
// The key of this game is to find a cycle that contain dots of same colour. Formally, 
// we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
// 1. These k dots are different: if i ≠ j then di is different from dj.
// 2. k is at least 4.
// 3. All dots belong to the same colour.
// 4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
// Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
// Assume input to be 0-indexed based.

// Input Format :
// Line 1 : Two integers N and M, the number of rows and columns of the board
// Next N lines : a string consisting of M characters, expressing colors of dots in each line. Each character is an uppercase Latin letter.

// Output Format :
// Return 1 if there is a cycle else return 0

// Constraints :
// 2 ≤ N, M ≤ 50

// Sample Input :
// 3 4
// AAAA
// ABCA
// AAAA

// Sample Output :
// 1


#include<bits/stdc++.h>
#define MAXN 51
using namespace std;

bool visited[MAXN][MAXN];
int d1[8]={1, 0,-1, 0};
int d2[8]={0, 1, 0,-1};

bool isValid(int i, int j, int m, int n)
{
    return (i>=0 && j>=0 && i<m && j<n);
}

bool connectingDots(char board[][MAXN], int i, int j, int start, int end, int size, int m, int n, char ch)
{
    if(start==i && end==j && size!=1)
    {
        if(size>=4)
            return true;
        return false;
    }
    
    if(size!=1)
        visited[start][end]=true;
    
    bool ans=false;
    for(int k=0;k<4;k++)
    {
        if(isValid(start+d1[k], end+d2[k], m, n) && board[start+d1[k]][end+d2[k]]==ch && visited[start+d1[k]][end+d2[k]]==false)
        {
            ans= ans ||connectingDots(board, i, j, start+d1[k], end+d2[k], size+1, m, n, ch);
        }
    }
    
    visited[start][end]=false;
    
    return ans;
}

int solve(char board[][MAXN],int m, int n)
{
	for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            char ch=board[i][j];
            memset(visited, false, sizeof(visited));
            if(connectingDots(board, i, j, i, j, 1, m, n, ch))
                return 1;
        }
    }
    
    return 0;
}

int main()
{
	int N,M,i;
	char board[MAXN][MAXN];
	cin>>N>>M;
	for(i = 0;i < N; i++){
		cin>>board[i];
	}
	cout<<solve(board,N,M)<<endl;
}