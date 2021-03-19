class Solution {
public:
    
    vector< pair<int, int> >graph[1001];
    int INF = 100000000;
    int ans[1001];
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        for(int i=0;i<=1000;i++){
            ans[i]=INF;
        }
        
        for(int i=0;i<times.size();i++){
            int x = times[i][0];
            int y = times[i][1];
            int w = times[i][2];
            graph[x].push_back({y,w});
        }
        
        ans[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0,k});
        
        while(!pq.empty()){
            int curr_w = pq.top().first;
            int curr_n = pq.top().second;
            pq.pop();
            
            for(auto node : graph[curr_n]){
                if(curr_w + node.second < ans[node.first]){
                    ans[node.first] = curr_w + node.second;
                    pq.push({ans[node.first], node.first});
                }
            }
        }
        
        int maxAns = -INF;
        
        for(int i=1;i<=n;i++){
            if(ans[i]==INF){
                return -1;
            }
            // cout<<ans[i] <<" ";
            maxAns = max(maxAns, ans[i]);
        }
        
        return maxAns;
    }
};