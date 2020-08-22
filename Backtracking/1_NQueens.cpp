//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;



bool isSafe(int **mat, int x, int y, int n)
{
 	int i=x-1,j=y-1;
    
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i--;
        j--;
    }
    
    i=x-1,j=y;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i--;
    }
    
    i=x,j=y-1;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        j--;
    }
    
    
    i=x+1,j=y+1;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i++;
        j++;
    }
    
    i=x+1,j=y;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i++;
    }
    
    i=x,j=y+1;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        j++;
    }
    
    i=x-1,j=y+1;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i--;
        j++;
    }
    
    i=x+1,j=y-1;
    while(i>=0&&j>=0&&i<n&&j<n)
    {
        if(mat[i][j]==1)
            return false;
        i++;
        j--;
    }
    
    return true;
    
}


void placeQueen(int **mat, int row,int total)
{
    if(row==total)
    {
        for(int i=0;i<total;i++)
        {
            for(int j=0;j<total;j++)
                cout<<mat[i][j]<<" ";
        }
        cout<<endl;
        return;
    }
    
    
    for(int i=0;i<total;i++)
    {
        if(isSafe(mat,row,i,total))
        {
            mat[row][i]=1;
            placeQueen(mat,row+1,total);
            mat[row][i]=0;
        }
    }
    
    
}
void placeNQueens(int n){
    
    int **mat= new int*[n];
    for(int i=0;i<n;i++)
    {
        mat[i]=new int[n];
        for(int j=0;j<n;j++)
            mat[i][j]=0;
    }
    
    placeQueen(mat,0,n);

}



int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);

}

