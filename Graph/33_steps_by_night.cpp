class solution{
    public:

    int dx[8]={2, 1, 1, 2, -1, -2, -2, -1};
    int dy[8]={-1, -2, 2, 1, -2, -1, 1, 2};
    bool vis[1001][1001];
    
    bool isValid(int x, int y, int n){
        return (x>=1&&y>=1&&x<=n&&y<=n&&vis[x][y]==false);
    }
    
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int N){
	    // Code here
	    
	    int sx=KnightPos[0], sy=KnightPos[1];
	    int tx=TargetPos[0], ty=TargetPos[1];
	    int graph[N+1][N+1];
	    
	    memset(graph, 0, sizeof(graph));
	    memset(vis, 0, sizeof(vis));
	    
	    queue<pair<int, int>>q;
	    
	    q.push({sx, sy});
	    vis[sx][sy]=true;
	    
	    while(!q.empty()){
	        int x = q.front().first;
	        int y = q.front().second;
	        q.pop();
	        
	        for(int i=0;i<8;i++){
	            int newX = x+dx[i];
	            int newY = y+dy[i];
	            
	            if(isValid(newX, newY, N)){
	                vis[newX][newY]=true;
	                q.push({newX, newY});
	                graph[newX][newY] = 1+ graph[x][y];
	            }
	        }
	    }
	    
	    return graph[tx][ty];
	}
};