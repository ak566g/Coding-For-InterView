//by Ankita Gupta

#include <boost/multiprecision/cpp_int.hpp>
#include<bits/stdc++.h>
using namespace boost::multiprecision;
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;

    while(t--){
        int a, y, x;
        cin>>a>>y>>x;
        int128_t ans = 0;
        if(a>=y){  
            ans = y*x;
        }else{
            ans = x*a+1;
        }
        cout<<ans<<"\n";
    }
}