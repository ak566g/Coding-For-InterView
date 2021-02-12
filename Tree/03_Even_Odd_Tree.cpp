/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        q.push(NULL);
        int level=0;
        vector<int>v;
        while(!q.empty()){
            TreeNode *front = q.front();
            if(front==NULL){
                for(int i=0;i<v.size();i++){
                    cout<<v[i]<<" ";
                }
                cout<<"\n";
                if(level%2==0){
                    for(int i=0;i<v.size();i++){
                        //cout<<v[i]<<" ";
                        if(v[i]%2==0){
                            return false;
                        }
                        
                        if(i){
                            if(v[i-1]>=v[i]){
                                return false;
                            }
                        }
                    }
                }else if(level%2==1){
                    for(int i=0;i<v.size();i++){
                        //cout<<v[i]<<" ";
                        if(v[i]%2==1){
                            return false;
                        }
                        if(i){
                            if(v[i-1]<=v[i]){
                                return false;
                            }
                        }
                    }
                }
                
                level++;
                vector<int>temp;
                swap(v,temp);
                q.pop();
                q.push(NULL);
                if(q.size()==1 && q.front()==NULL){
                    break;
                }
                continue;
            }
            q.pop();
            v.push_back(front->val);
            if(front->left!=NULL){
                q.push(front->left);
            }
            
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
        
        return true;
    }
};