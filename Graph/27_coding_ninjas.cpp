#include<bits/stdc++.h>
bool visited[1000][1000];
int d1[]={1,0,-1,0,1,-1,1,-1};
int d2[]={0,1,0,-1,1,-1,-1,1};

bool validDirection(int i, int j, int m, int n)
{
    if(i>=0&&j>=0&&i<m&&j<n)
    return true;

    return false;
}

bool check(vector<vector<char>>&Graph , int m, int n, int i, int j, string s)
{
    bool ans=false;
    if(s.size()==0)
    return true;

    for(int k=0;k<8;k++){
        if(validDirection(i+d1[k],j+d2[k],m,n))
        {
            if(Graph[i+d1[k]][j+d2[k]]==s[0]&&visited[i+d1[k]][j+d2[k]]==false){
                visited[i+d1[k]][j+d2[k]]=true;
                ans= check(Graph,m,n,i+d1[k],j+d2[k],s.substr(1));
                if(ans)
                return ans;
            }
        }
    }   

    visited[i][j]=false;
    return ans;
}



int hasPath(vector<vector<char>> Graph,int m, int n)
{
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            visited[i][j]=false;
        }
    }

    string s="CODINGNINJA";

    memset(visited,false,sizeof(visited));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(Graph[i][j]=='C'){
                bool ans=check(Graph,m,n,i,j,s.substr(1));
                if(ans)
                return 1;
            }
        }
    }
    return 0;
}
