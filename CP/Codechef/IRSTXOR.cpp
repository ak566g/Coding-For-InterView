//by Ankita Gupta

#include<bits/stdc++.h>
#define ull long long
using namespace std;
vector<ull>pof2;

void init(){
    ull start = 1;
    while(start<=1000000000){
        pof2.push_back(start);
        start*=2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    init();
    int t;
    cin>>t;
    while (t--)
    {
        ull n;
        cin>>n;
        auto it = upper_bound(pof2.begin(), pof2.end(), n);
        int index= it-pof2.begin();
        ull p = pof2[index];
        
        ull a = p/2 - 1;
        ull b = a^n;
        ull ans = a*b;
        cout<<ans<<"\n";

    }
}