class Solution{
	public:
	vector<int>ans;
	int inDegree[10001];
	
	
	void topological(int V, vector<int> adj[]){
	    
	    queue<int>q;
	    for(int i=0;i<V;i++){
	        if(inDegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int curr = q.front();
	        q.pop();
	        ans.push_back(curr);
	        
	        for(int i=0;i<adj[curr].size();i++){
	            int vertex = adj[curr][i];
	            inDegree[vertex]--;
	            
	            if(inDegree[vertex]==0){
	                q.push(vertex);
	            }
	        }
	    }
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    memset(inDegree, 0, sizeof(inDegree));
	    
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            int y = adj[i][j];
	            inDegree[y]++;
	        }
	    }
	    
	    topological(V, adj);
	    return ans;
	}
};