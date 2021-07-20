#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long g[3][3];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    int count = 1;
    while (t--){
        cin>>g[0][0]>>g[0][1]>>g[0][2];
        cin>>g[1][0]>>g[1][2];
        cin>>g[2][0]>>g[2][1]>>g[2][2];

        ll can[4];
        can[0] = (g[0][0]+g[2][2]);
        can[1] = (g[0][1]+g[2][1]);
        can[2] = (g[0][2]+g[2][0]);
        can[3] = (g[1][0]+g[1][2]);
        int alreadyCount = 0;

        if(g[0][0]+g[2][0]==2*g[1][0]){
            alreadyCount++;
        }

        if(g[0][2]+g[2][2]==2*g[1][2]){
            alreadyCount++;
        }
        
        if(g[0][0]+g[0][2]==2*g[0][1]){
            alreadyCount++;
        }
        
        if(g[2][0]+g[2][2]==2*g[2][1]){
            alreadyCount++;
        }

        int maxCand1 = 0;
        int maxCand2 = 0;
        int maxCand3 = 0;
        int maxCand4 = 0;
        // for canditate 0

        if(g[0][0]+g[2][2]==can[0]){
            maxCand1++;
        }

        if(g[0][2]+g[2][0]==can[0]){
            maxCand1++;
        }
        
        if(g[0][1]+g[2][1]==can[0]){
            maxCand1++;
        }
        
        if(g[1][0]+g[1][2]==can[0]){
            maxCand1++;
        }

        // for candidate 1
        if(g[0][0]+g[2][2]==can[1]){
            maxCand2++;
        }

        if(g[0][2]+g[2][0]==can[1]){
            maxCand2++;
        }
        
        if(g[0][1]+g[2][1]==can[1]){
            maxCand2++;
        }
        
        if(g[1][0]+g[1][2]==can[1]){
            maxCand2++;
        }

        // for candidate 2
        if(g[0][0]+g[2][2]==can[2]){
            maxCand3++;
        }

        if(g[0][2]+g[2][0]==can[2]){
            maxCand3++;
        }
        
        if(g[0][1]+g[2][1]==can[2]){
            maxCand3++;
        }
        
        if(g[1][0]+g[1][2]==can[2]){
            maxCand3++;
        }

        // for candidate 3

        if(g[0][0]+g[2][2]==can[3]){
            maxCand4++;
        }

        if(g[0][2]+g[2][0]==can[3]){
            maxCand4++;
        }
        
        if(g[0][1]+g[2][1]==can[3]){
            maxCand4++;
        }
        
        if(g[1][0]+g[1][2]==can[3]){
            maxCand4++;
        }

        int ans = alreadyCount + max({maxCand1, maxCand2, maxCand3, maxCand4});

        // cout<<ans<<"\n";

        cout<<"Case #"<<count<<": "<<ans<<"\n";
        count++;
    }
    

    return 0;
}
