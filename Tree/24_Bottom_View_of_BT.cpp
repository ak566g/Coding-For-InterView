vector <int> bottomView(Node *root)
{
    map<int, int>mp;
    queue<pair<Node*, int>>q;
    vector<int>ans;
    
    q.push({root, 0});
    
    while(!q.empty()){
        Node* curn = q.front().first;
        int curl = q.front().second;
        q.pop();
        
        mp[curl]=curn->data;
        
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
