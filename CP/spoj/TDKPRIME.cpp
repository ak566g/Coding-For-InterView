//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#define nmax 90000000

vector<int>primes;
bool sieve[90000001];

void init(){
    memset(sieve, true, sizeof(sieve));
    sieve[0]=false;
    sieve[1]=false;

    for(int i=2;i*i<=nmax;i++){
        if(sieve[i]){
            for(int j=2*i;j<=nmax;j+=i){
                sieve[j]=false;
            }
        }
    }

    for(int i=2;i<=nmax;i++){
        if(sieve[i]){
            primes.push_back(i);
        }
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
        int n;
        cin>>n;
        cout<<primes[n-1]<<"\n";
    }
    
}