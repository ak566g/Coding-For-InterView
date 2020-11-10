// by Ankita Gupta
// Determine if we the given undirected graph has cycle or not.

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int parent;
        int rank;
};
int edges[1000][1000];
vector<Node>vertices(1000);

int findParent(int v, int n)
{
    if(vertices[v].parent==-1)
    {
        return v;
    }
    
    return vertices[v].parent = findParent(vertices[v].parent, n);
}

void union_operation(int v1, int v2, int n)
{
    if(vertices[v1].rank > vertices[v2].rank)
    {
        vertices[v2].parent = v1;
    }
    else if(vertices[v1].rank < vertices[v2].rank)
    {
        vertices[v1].parent = v2;
    }
    else
    {
        vertices[v1].parent = v2;
        vertices[v2].rank +=1;
    }
}

bool isCyclic(int n)
{
    for(int i=0; i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(edges[i][j]==1)
            {
                int parent1 = findParent(i, n);
                int parent2 = findParent(j, n);

                if(parent1 == parent2)
                {
                    return true;
                }

                union_operation(parent1 , parent2, n);
            }
        }
    }
    return false;
}

int main(){

    int V, E;
    cin>>V>>E;
    memset(edges, 0, sizeof(edges));
    for(int i=0;i<V;i++)
    {
        vertices[i].parent =-1;
        vertices[i].rank = 0;
    }

    for(int i=0;i<E;i++)
    {
        int x, y;
        cin>>x>>y;

        edges[x][y]=1;
    }

    if(isCyclic(V))
    {
        cout<<"Yes";
    }
    else
    {
        cout<<"No";
    }
    

}