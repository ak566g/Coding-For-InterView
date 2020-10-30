// https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/kingdom-of-monkeys/

//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;
#define ll long long
vector<int>edges[100001];
int visited[100001];
int bananas[100001];


void dfs(int si, ll &value)
{
    visited[si]=true;
    value+=bananas[si];

    for(auto i: edges[si])
    {
        if(visited[i]==false)
        {
            dfs(i, value);
        }
    }
}

ll prize(int n)
{
    ll maxprize=0;
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            ll temp=0;
            dfs(i,temp);
            maxprize = max(maxprize, temp);
        }
    }

    return maxprize;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        for(int i=0;i<=100000;i++)
        {
            visited[i]=false;
            edges[i].clear();
            bananas[i]=0;
        }

        int n, m;
        cin>>n>>m;

        for(int i=0;i<m;i++)
        {
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        for(int i=1;i<=n;i++)
        {
            cin>>bananas[i];
        }
        cout<<prize(n)<<"\n";
    }
}