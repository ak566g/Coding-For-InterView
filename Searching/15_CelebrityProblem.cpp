//by Ankita Gupta
// You are in a party of N people, where only one person is known to everyone. 
// Such a person may be present in the party, if yes, (s)he doesn’t know anyone in the party. 
// Your task is to find the stranger (celebrity) in party.


#include<bits/stdc++.h>
using namespace std;
#define MAX 501

int getId(int M[MAX][MAX],int n);

int main()
{
    int T;
    cin>>T;
    int M[MAX][MAX];
    while(T--)
    {
        int N;
        cin>>N;
        memset(M,0,sizeof M);
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>M[i][j];
            }
        }
        cout<<getId(M,N)<<endl;

    }
}

// } Driver Code Ends


// The task is to complete this function

// M[][]: input matrix
// n: size of matrix (n*n)
int getId(int M[MAX][MAX], int n)
{
    //Your code here
    // stack<int>st;
    // for(int i=0;i<n;i++){
    //     st.push(i);
    // }
    
    // while(st.size()>=2){
        
    //     int a=st.top();
    //     st.pop();
    //     int b=st.top();
    //     st.pop();
        
    //     if(M[a][b]==1)
    //          st.push(b);
    //     else
    //         st.push(a);
        
    // }

    
    // int a=st.top();
    
    
    
    // for(int i=0;i<n;i++){
    //     if(i!=a){
    //     if(M[a][i]==1||M[i][a]==0)
    //     return -1;}
    // }
    
    // return a;
    
    int x=0, y=n-1;
    
    while(x<y)
    {
        if(M[x][y]==1){
            x++;
        }
        else
        {
            y--;
        }
        
    }
    
    for(int i=0;i<n;i++){
        if(i!=x){
            if(M[x][i]==1||M[i][x]==0)
            return -1;
        }
    }
    
    return x;
}