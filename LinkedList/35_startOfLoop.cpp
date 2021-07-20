/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* Solution::detectCycle(ListNode* head) {
    ListNode* slow=head, *fast=head;
    bool loop = false;
    while(slow!=NULL && fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            loop = true;
            break;
        }
    }
    
    if(!loop){
        return NULL;
    }
    
    fast = head;
    while(slow!=fast){
        slow=slow->next;
        fast=fast->next;
    }
    
    return fast;
}