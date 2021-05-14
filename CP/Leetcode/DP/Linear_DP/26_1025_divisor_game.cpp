// class Solution {
// public:
//     bool divisorGame(int n) {
//         return n%2==0;
//     }
// };

class Solution {
public:
    bool divisorGame(int n) {
       if(n==1)return false; //base case if n==1 alice can't select any number such that n%i==0 so false
     
        // create  a dp table of size n+1 and we fill it in bottom-up fashion i.e if n= 1,2,3...
        //then whether alice wins in this cases or not
        int dp[n+1];
        memset(dp, 0, sizeof(dp)); //initialize all values as false
        dp[2]=true; //base case if n==2 2nd player can't make any move so alice wins
        
        //Now fill in bottom-up fashion: for each i we check if alice wins fornot by looping
        //values from j=1 to j<=sqrt(i) and check if any values of j in this range divides i
        //and dp[i-j] ==false then alice wins this game 
        for(int i=3;i<=n;i++)
        {
            for(int j=1;j*j<=i;j++){
                if(i%j==0 && dp[i-j]== false)
                    dp[i]=true;
            }
        }
        //return final ans 
        return dp[n];
    }
};