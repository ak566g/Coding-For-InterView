#define pi pair<int, int>
#define ppi pair<int, pair<int, int>>
#define INF 100000001

class Solution {
public:
    
    vector<pi>graph[1001];
    
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int K) {
        int e = f.size();
        
        for(int i=0;i<e;i++){
            int x = f[i][0];
            int y = f[i][1];
            int p = f[i][2];
            
            graph[x].push_back({y, p});
        }
        
        priority_queue <ppi, vector<ppi>, greater<ppi> > pq;
        
        pq.push({0, {src, K+1}});
        
        while(!pq.empty()){
            int curPrice = pq.top().first;
            int curNode = pq.top().second.first;
            int stepsRem = pq.top().second.second;
            pq.pop();
            
            if(stepsRem<0)
                continue;
            
            if(dst==curNode){
                return curPrice;
            }
            
            for(auto child : graph[curNode]){
                int nextNode = child.first;
                int nextPrice = child.second;
                
                pq.push({curPrice + nextPrice, {nextNode, stepsRem-1}});
            }
        }
        
        return -1;
    }
};