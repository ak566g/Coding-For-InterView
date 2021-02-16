class Solution {
public:


    bool helper(int s, int parent, vector<int>adj[], bool *visited){
        visited[s]=true;
       // cout<<s<<" ";
        
        for(auto child:adj[s]){
            if(visited[child] == false){
                bool temp = helper(child, s, adj, visited);
                if(temp){
                    return true;
                }
            }
            else if(child!=parent){
                return true;
            }
        }
        
        return false;
    }
    
	bool isCycle(int V, vector<int>adj[]){
	   bool visited[V+1];
	   
	   for(int i=0;i<=V;i++){
	       visited[i]=false;
	   }
	   
	    for(int i=0;i<V;i++){
	        if(visited[i]==false){
	            if(helper(i, -1, adj, visited)){
	                return true;
	            }        
	        }
	    }
	    // cout<<"\n";
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends