//by Ankita Gupta

//by Ankita Gupta


        

int main()
{
  	int v, e;
  	cin >> v >> e;
	
    memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(visited));
    memset(cost, 0, sizeof(cost));
    
    for(int i=0; i<e; i++)
    {
        int si, ei, w;
        cin>>si>>ei>>w;
        
        edges[si][ei]=w;
        edges[ei][si]=w;
    }
 	
	
    dijkstras(v);
    
  	return 0;
}

        

int main()
{
  	int v, e;
  	cin >> v >> e;
	
    memset(edges, 0, sizeof(edges));
    memset(visited, false, sizeof(visited));
    memset(cost, 0, sizeof(cost));
    
    for(int i=0; i<e; i++)
    {
        int si, ei, w;
        cin>>si>>ei>>w;
        
        edges[si][ei]=w;
        edges[ei][si]=w;
    }
 	
	
    dijkstras(v);
    
  	return 0;
}
