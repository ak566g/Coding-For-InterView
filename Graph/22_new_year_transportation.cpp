// https://codeforces.com/problemset/problem/500/A

//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[100001];
bool visited[100001];
int a[100001];

void dfs(int si)
{
    visited[si]=true;

    for(auto i : graph[si])
    {
        if(visited[i]==false)
        {
            dfs(i);
        }
    }
}

int main(){
    int n, m;
    cin>>n>>m;

    for(int i=1;i<=n-1;i++)
    {
        cin>>a[i];
    }
    int vertex=n;
    for(int i=1;i<=n-1;i++)
    {
        int x = i+a[i];
        int y= i;
        //cout<<y<<" "<<x<<"\n";
        //graph[x].push_back(y);
        graph[y].push_back(x);
    }


    memset(visited, 0, sizeof(visited));

    // for(int i=1;i<=n;i++)
    // {
    //     cout<<visited[i]<<" ";
    // }

    dfs(1);


    if(visited[m])
    {
        cout<<"YES";
    }
    else
    {
        cout<<"NO";
    }
    

}