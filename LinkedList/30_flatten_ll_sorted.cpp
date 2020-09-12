//by Ankita Gupta
// https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

Node* merge(Node *head1, Node *head2)
{
    if(head1==NULL)
    return head2;
    
    if(head2==NULL)
    return head1;
    
    Node *ans;
    if(head1->data<head2->data){
        ans=head1;
        head1->bottom=merge(head1->bottom,head2);
    }
    else{
        ans=head2;
        head2->bottom=merge(head1,head2->bottom);
    }    
    ans->next=NULL;
    return ans;
}
    
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL)
   return root;
   
   return merge(root, flatten(root->next));
}

