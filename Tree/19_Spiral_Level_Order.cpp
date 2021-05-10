vector<int> findSpiral(Node *root)
{
    
    if(root==NULL){
        return {};
    }
    
    vector<int>ans;
    
    stack<Node*>s1;
    stack<Node*>s2;
    
    s2.push(root);
    
    while(true){
        while(s1.size()>0){
            Node* cur = s1.top();
            ans.push_back(cur->data);
            s1.pop();
            if(cur->left){
                s2.push(cur->left);
            }
            
            if(cur->right){
                s2.push(cur->right);
            }
        }
        while(s2.size()>0){
            Node* cur = s2.top();
            ans.push_back(cur->data);
            s2.pop();
            
            if(cur->right){
                s1.push(cur->right);
            }
            
            if(cur->left){
                s1.push(cur->left);
            }
        }
        
        if(s1.size()==0 && s2.size()==0){
            break;
        }
    }
    return ans;
}
