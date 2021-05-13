class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        map<int, vector<int>>mp;
        queue<pair<Node*, int>>q;
        q.push({root, 0});
        vector<int>ans;
        
        while(!q.empty()){
            Node* cur = q.front().first;
            int level=q.front().second;
            q.pop();
            
            mp[level].push_back(cur->data);
            
            if(cur->left){
                q.push({cur->left, level-1});
            }
            
            if(cur->right){
                q.push({cur->right, level+1});
            }
        }
        
        
        for(auto it : mp){
            for(auto num : it.second){
                ans.push_back(num);
            }
        }
        return ans;
    }
};
