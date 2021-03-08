class Solution{
	public:

    vector<int>tr[5001];
    bool visited[5001];
    vector<int>scc;
    vector<int>order;
    
    void dfs1(vector<int> adj[], int node){
        visited[node]=true;
        
        for(auto i:adj[node]){
            if(!visited[i]){
                dfs1(adj, i);
            }
        }
        
        order.push_back(node);
    }
    
    void dfs2(vector<int> tr[], int node){
        visited[node]=true;
        
        for(auto i:tr[node]){
            if(!visited[i]){
                dfs2(tr, i);
            }
        }
        
        scc.push_back(node);
    }
    
    int kosaraju(int V, vector<int> adj[]) {
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                tr[adj[i][j]].push_back(i);
            }
        }
        
        memset(visited, false, sizeof(visited));
        
        for(int i=0;i<V;i++){
            if(!visited[i]){
                dfs1(adj, i);
            }
        }
        
        reverse(order.begin(), order.end());
        memset(visited, false, sizeof(visited));
        int ans =0;
        for(int i=0;i<V;i++){
            if(!visited[order[i]]){
                dfs2(tr,order[i]);
                ans++;
            }
        }
        return ans;
    }
};