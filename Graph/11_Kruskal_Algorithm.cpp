//by Ankita Gupta


// Given an undirected, connected and weighted graph G(V, E) with V number of vertices (which are numbered from 0 to V-1) and E number of edges.
// Find and print the Minimum Spanning Tree (MST) using Kruskal's algorithm.

// For printing MST follow the steps -
// 1. In one line, print an edge which is part of MST in the format -
// v1 v2 w
// where, v1 and v2 are the vertices of the edge which is included in MST and whose weight is w. And v1 <= v2 i.e. print the smaller vertex first while printing an edge.
// 2. Print V-1 edges in above format in different lines.

// Note : Order of different edges doesn't matter.

// Input Format :
// Line 1: Two Integers V and E (separated by space)
// Next E lines : Three integers ei, ej and wi, denoting that there exists an edge between vertex ei and vertex ej with weight wi (separated by space)

// Output Format :
// MST

// Constraints :
// 2 <= V, E <= 10^5

// Sample Input 1 :
// 4 4
// 0 1 3
// 0 3 5
// 1 2 1
// 2 3 8

// Sample Output 1 :
// 1 2 1
// 0 1 3
// 0 3 5

// Time Complexity
// E * logE + E * V

// If union find algorithm will replaced by union by path compression then time complexity will
// reduced to
// E*logE + E*logV

#include<bits/stdc++.h>
using namespace std;

class Edge{
  	public:
    int s;
    int e;
    int w;
};

bool cmp(Edge &e1, Edge &e2)
{
	return e1.w<=e2.w;
}

int findParent(int s, int parent[])
{
    if(parent[s]==s)
        return s;
    
    return findParent(parent[s], parent);
}

vector<Edge> Kruskals(vector<Edge>edge, int v)
{
    vector<Edge>ans;
    
    int parent[v];
    
    for(int i=0;i<v;i++)
        parent[i]=i;
    
    int count=0;
    int i=0;
    while(count<v-1)
    {
        Edge temp = edge[i];
        
        int parentStart=findParent(edge[i].s, parent);
        int parentEnd = findParent(edge[i].e, parent);
        
        if(parentStart!=parentEnd)
        {
            ans.push_back(temp);
            count++;
        }
        
        parent[parentStart]=parentEnd;
        
        i++;
        
    }
    
    return ans;
}

int main()
{
  	int V, E;
  	cin >> V >> E;
	
    vector<Edge>edge;
    
    for(int i=0;i<E;i++)
    {
        int s,e,w;
        cin>>s>>e>>w;
        
        Edge temp;
        temp.s=s;
        temp.e=e;
        temp.w=w;
        
        edge.push_back(temp);
        
        temp.s=e;
        temp.e=s;
        temp.w=w;
        
        edge.push_back(temp);
    }
    
    sort(edge.begin(), edge.end(),cmp);
    
    vector<Edge>ans;
    ans= Kruskals(edge, V);
    
    for(int i=0;i<ans.size();i++)
    {
        if(ans[i].s <=ans[i].e)
        {
            cout<<ans[i].s<<" "<<ans[i].e<<" "<<ans[i].w<<"\n";
        }
        else
        {
            cout<<ans[i].e<<" "<<ans[i].s<<" "<<ans[i].w<<"\n";
        }
    }
    
  	return 0;
}
