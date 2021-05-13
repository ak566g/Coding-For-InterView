class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        vector<int>ans;
        map<int, int>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()){
            Node* curn = q.front().first;
            int curl = q.front().second;
            q.pop();
            
            if(mp.count(curl)==0){
                mp[curl]=curn->data;
            }
            
            if(curn->left){
                q.push({curn->left, curl-1});
            }
            
            if(curn->right){
                q.push({curn->right, curl+1});
            }
        }
        
        
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }

};
