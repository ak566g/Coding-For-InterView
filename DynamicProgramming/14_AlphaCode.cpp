//by Ankita Gupta

// Input will consist of multiple input sets. Each set will consist of a single line of at most 5000 digits representing a valid encryption (for example, no line will begin with a 0). There will be no spaces between the digits. An input line of ‘0’ will terminate the input and should not be processed.
// Output
// For each input set, output the number of possible decodings for the input string. Print your answer taking modulo "10^9+7"
// Sample Input:
// 25114
// 1111111111
// 3333333333
// 0
// Sample Output:
// 6
// 89
// 1

#include<bits/stdc++.h>
using namespace std;

// Recursive ..

// ll alphaCode(string number)
// {
//     if(number.size()==1||number.size()==0)
//         return 1;
    
//     if(number[0]=='0')
//         return 0;
    
//     int num1=number[0]-'0';
//     int num2=number[1]-'0';
//     int currentNum= num1*10+num2;
    
//     if(currentNum==10||currentNum==20){
//         return alphaCode(number.substr(2));
//     }
//     else if(currentNum>10&&currentNum<=26)
//     {
//         return alphaCode(number.substr(1))+alphaCode(number.substr(2));
//     }
//     else{
//         return alphaCode(number.substr(1));
//     }        
// }


// Dynamic Programming Approach
ll alphaCode(string number)
{
    int n=number.size();
    ll dp[n+1];
    dp[0]=1;
    dp[1]=1;
    
    for(int i=2;i<=n;i++)
    {
        int n1=number[i-2]-'0';
        int n2=number[i-1]-'0';
        int currentNum= n1*10+n2;
        
        if(currentNum==0||n2==0&&n1>=3)
            return 0;
        
        if(currentNum==10||currentNum==20){
            dp[i]=dp[i-2]%mod;
        }else if(currentNum>10&&currentNum<=26){
            dp[i]=(dp[i-1]%mod+dp[i-2]%mod)%mod;
        }else{
            dp[i]=dp[i-1]%mod;
        }
    }
    return dp[n];
}


int main()
{
    
    string number;
    
    while(1)
    {
        cin>>number;
        if(number.compare("0")==0){
            break;
        }
        
    	cout<<alphaCode(number)<<"\n";
    }
    return 0;
}
