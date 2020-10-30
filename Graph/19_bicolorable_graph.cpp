//by Ankita Gupta

#include<bits/stdc++.h>
using namespace std;

bool bipartile(vector<int>edges[], int n)
{
    if(n==0)
    return true;

    unordered_set<int>sets[2];
    vector<int>pending;
    sets[0].insert(0);
    pending.push_back(0);

    while(pending.size()>0)
    {
        int current=pending.back();
        pending.pop_back();

        int currentSet= sets[0].count(current)>0?0:1;

        for(int i=0;i<edges[current].size();i++)
        {
            int adj = edges[current][i];
            if(sets[currentSet].count(adj)>0)
                return false;
            else if(sets[1-currentSet].count(adj)==0)
            {
                pending.push_back(adj);
                sets[1-currentSet].insert(adj);
            }
        }
    }
    return true;
}

int main(){

    while(true)
    {
        int n;
        cin>>n;

        if(n==0)
        break;

        vector<int>edges[n];
        int m;

        cin>>m;

        for(int i=0;i<m;i++)
        {
            int x, y;
            cin>>x>>y;
            edges[x].push_back(y);
            edges[y].push_back(x);
        }

        bool ans = bipartile(edges, n);
        if(ans)
        {
            cout<<"Bi-Colorable"<<"\n";
        }
        else
        {
            cout<<"Not Bi-Colorable"<<"\n";
        }
    }
}