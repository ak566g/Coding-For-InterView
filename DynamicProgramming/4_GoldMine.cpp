//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

int isValid(int i,int j, int m, int n){
    if(i>=0&&j>=0&&i<m&&j<n)
    return true;
    
    return false;
}

int goldMine(int **mat, int m, int n)
{

    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            int x=INT_MIN;
            int y=INT_MIN;
            int z=INT_MIN;
            
            if(isValid(j-1,i-1,m,n)){
                x=mat[j-1][i-1];
            }
            if(isValid(j+1,i-1,m,n)){
                y=mat[j+1][i-1];
            }
            if(isValid(j,i-1,m,n)){
                z=mat[j][i-1];
            }
            
            int number=max(x,max(y,z));
            mat[j][i]+=number;
            
        }
    }
    int ans=INT_MIN;
    for(int i=0;i<m;i++){
        if(mat[i][n-1]>ans){
            ans=mat[i][n-1];
        }
    }
    
    return ans;
}

int main()
 {
	//code
	int t;
	cin>>t;
	
	while(t--){
	    int m,n;
	    cin>>m>>n;
	    
	    int **mat= new int*[m];
	    
	    for(int i=0;i<m;i++){
	        mat[i]=new int[n];
	    }
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            cin>>mat[i][j];
	        }
	    }
	    
	    cout<<goldMine(mat,m,n)<<"\n";
	}
	
	return 0;
}