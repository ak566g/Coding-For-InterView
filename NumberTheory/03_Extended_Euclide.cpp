//by Ankita Gupta

// Diophantine
// Polynomial equation, for which integer soln exists.
// Linear Diophantine --
// ax+by=c
// x and y are integers only if gcd(a,b) divides c

#include<bits/stdc++.h>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};

Triplet extended_euclid(int a, int b)
{
    // Extended Euclid Algorithm
    if(b==0)
    {
        Triplet ans;
        ans.gcd=a;
        ans.x=1;
        ans.y=0;
        return ans;
    }

    Triplet smallAns = extended_euclid(b, a%b);
    Triplet ans;
    ans.gcd= smallAns.gcd;
    ans.x = smallAns.y;
    ans.y = smallAns.x - (a/b)*smallAns.y;
    return ans;
}

int main(){

    Triplet obj = extended_euclid(16, 10);
    cout<<obj.gcd<<" "<<obj.x<<" "<<obj.y;

}