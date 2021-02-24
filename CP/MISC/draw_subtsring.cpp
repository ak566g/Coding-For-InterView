//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;


int lenOfSub(string x, string y)
{
    int n= x.size();
    int m= y.size();
    int dp[n+1][m+1];

    for (int i = 0; i <= m; i++) 
        for (int j = 0; j <= n; j++) 
            dp[i][j] = 0; 

     for (int i = 1; i <= m; i++) { 
        for (int j = 1; j <= n; j++) { 
            if (x[j - 1] == y[i - 1]) 
                dp[i][j] = 1 + dp[i - 1][j - 1]; 
            else
                dp[i][j] = dp[i][j - 1]; 
        } 
    } 
  
    int ans = 0; 
    for (int i = 1; i <= m; i++) 
        ans = max(ans, dp[i][n]); 
  
    return ans; 
  
}

string replaceChars(string str)
{
    string draw = str;
    for(int i=0;i<draw.size();i++)
    {
        if(draw[i]=='a' || draw[i]=='o')
        {
            draw[i]='$';
        }

        else if(draw[i]=='t'|| draw[i]=='l')
        {
            draw[i]='#';
        }
    }

    return draw;
}

int main(){
    int n;
    cin>>n;

    string draw;
    cin>>draw;

    draw = replaceChars(draw);

    string tickets[n];

    for(int i=0;i<n;i++)
    {
        cin>>tickets[i];
        tickets[i] = replaceChars(tickets[i]);

        // cout<<tickets[i]<<" ";
    }

    int k;
    cin>>k;

    int result = 0;

    for(int i=0;i<n;i++){
        int m = tickets[i].size();
        if(m<=k)
        {
            result++;
        }
        else
        {
            // we can ignore atmost k element.
            int len = lenOfSub(draw, tickets[i]);
            if(len+k>=m)
            {
                result++;
            }
        }
    }

    cout<<result;
}