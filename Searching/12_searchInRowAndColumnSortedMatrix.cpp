//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool findInMatrix(int **mat, int m, int n, int key)
{
    int i=0,j=n-1;
    
    while((i<=m-1)&&(j>=0))
    {
        if(mat[i][j]==key)
        return true;
        
        else if(mat[i][j]>key)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    
    return false;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    
	    int **mat = new int*[m];
	    
	    for(int i=0;i<m;i++)
	    {
	        mat[i]=new int[n];
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	        }
	    }
	    
	    int key;
	    cin>>key;
	    
	    cout<<findInMatrix(mat,m,n,key)<<"\n";
	}
	return 0;
}