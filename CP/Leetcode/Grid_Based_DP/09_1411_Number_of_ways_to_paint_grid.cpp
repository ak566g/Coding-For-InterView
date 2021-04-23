#define ll long long

class Solution {
public:
    
    int mod = pow(10, 9) + 7;
    
    int numOfWays(int n) {
        ll two[n+1];
        ll three[n+1];
        two[1]=6;
        three[1]=6;
        
        for(int i=2;i<=n;i++){
            two[i] = (3*two[i-1]  + 2*three[i-1])%mod;
            three[i] = (2*two[i-1]  + 2*three[i-1])%mod;
        }
        
        return (two[n]+three[n])%mod;
    }
};