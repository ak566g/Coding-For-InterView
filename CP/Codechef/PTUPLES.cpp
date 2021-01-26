//by Ankita Gupta

#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

bool seive[MAX];

void init()
{
    for(int i=0;i<MAX;i++)
    {
        seive[i]=true;
    }

    for(int i=2;i<MAX;i++)
    {
        if(seive[i]==true)
        {
            for(int j=2*i;j<MAX;j+=i)
            {
                seive[j]=false;
            }
        }
    }

    seive[0]=false;
    seive[1]=false;
}

int main(){
    init();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int count[MAX];
    for(int i=0;i<MAX;i++){
        count[i]=0;
    }

    for(int i=2;i<MAX;i++){
        if(seive[i]==true && seive[i-2]==true){
            count[i]=count[i-1]+1;
        }
        else{
            count[i]=count[i-1];
        }
    }

    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;
        // for(int i=1;primes[i]<=n;i++){
        //     int a = 2;
        //     int b = primes[i];
        //     int c = a+b;

        //     if(a<=n&&b<=n&&c<=n && seive[c]==true)
        //     count++;
        // }
        printf("%d\n", count[n]);
    }

}