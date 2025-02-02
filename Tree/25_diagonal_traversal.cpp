vector<int> diagonal(Node *root)
{
   // your code here
   
   vector<int>ans;
   
   queue<Node*>q;
   q.push(root);
   
   while(!q.empty()){
       Node* cur = q.front();
       q.pop();
       
       while(cur!=NULL){
           ans.push_back(cur->data);
           if(cur->left)
           q.push(cur->left);
           
           cur=cur->right;
       }
   }
   
   return ans;
}