#include<bits/stdc++.h>
#define ll long long
using namespace std;
int board[1001][1001];

int d1[]={-2, -2, -1, -1,  1, 1,  2, 2};
int d2[]={-1,  1, -2,  2, -2, 2, -1, 1};
bool visited[1001][1001];
ll fact [10000001];

bool isValid(int i, int j, int n, int m)
{
    return (i>=1&& j>=1 && i<=n && j<=m && board[i][j]==1 && visited[i][j]==false);
}

void init()
{
    fact[0]=1;
    ll mod= (ll)pow(10,9)+7;
    for(ll i=1;i<=10000000;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
}

void dfs(int x, int y, int n, int m, ll &count)
{
    visited[x][y]=true;
    count++;
    
    for(int i=0;i<8;i++)
    {
        if(isValid(x+d1[i],y+d2[i], n, m))
        {
            dfs(x+d1[i],y+d2[i], n, m, count);
        }
    }
}

int main()
{
    init();
    
	int t;
    cin>>t;
    ll mod = (ll)pow(10,9)+7;
    
    while(t--)
    {
        int n, m, q;
        cin>>n>>m>>q;
        
        memset(board,0,sizeof(board));
        memset(visited, false, sizeof(visited));
        for(int i=0;i<q;i++)
        {
            int x,y;
            cin>>x>>y;
            board[x][y]=1;
        }
        
        
     
        ll ans=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(visited[i][j]==false && board[i][j]==1)
                {
                    ll count=0;
                    dfs(i, j, n, m, count);
                    ans =(ans*fact[count])%mod;
                }
            }
        }
     
        cout<<ans<<endl;
        
    }
    
	return 0;
}
