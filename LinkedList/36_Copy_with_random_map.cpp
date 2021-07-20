/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
 
#define Node RandomListNode
Node* Solution::copyRandomList(RandomListNode* head) {
    unordered_map<Node* , Node*>um;
    Node *temp = head;
    
    while(temp){
        Node* newnode = new Node(temp->label);
        um[temp] = newnode;
        temp = temp->next;
    }
    
    temp = head;
    Node* ans = NULL;
    Node* next = NULL;
    while(temp){
        if(ans == NULL){
            ans = um[temp];
            ans->next = um[temp->next];
            ans->random = um[temp->random];
            next = ans;
        }
        
        else{
            next->next = um[temp];
            next = next->next;
            next->next = um[temp->next];
            next->random = um[temp->random];
        }
        
        temp = temp->next;
    }
    
    return ans;
}
