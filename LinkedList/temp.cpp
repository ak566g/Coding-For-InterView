Node *midPoint(Node *head)
{
    Node *slow = head, *fast = head->next;
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *head1, Node *head2)
{
    if(head1 == NULL)
    {
        return head2;
    }
    
    if(head2 == NULL)
    {
        return head1;
    }
    
    
    Node *fh = NULL, *ft = NULL;

    if(head1->data < head2->data)
    {
        fh = head1;
        ft = head1;
        head1 = head1->next;
    }
    else
    {
        fh = head2;
        ft = head2;
        head2 = head2->next;
    }
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data > head2->data)
        {
            ft->next = head2;
            ft = head2;
            head2 = head2->next;
        }

        else
        {
            ft->next = head1;
            ft = head1;
            head1 = head1->next;
        }
    }

    // while(head1 != NULL)
    // {
    //     ft->next = head1;
    //     ft = head1;
    //     head1 = head1->next;
    // }
    // while(head2 != NULL)
    // {
    //     ft->next = head2;
    //     ft = head2;
    //     head2 = head2->next;
    // }
    
    if(head1 == NULL)
    {
        ft->next=head2;
    }
    else
    {
        ft->next = head1;
    }
    
    return fh;
}



Node *mergeSort(Node *head)
{
    if(head == NULL || head->next==NULL)
    {
        return head;
    }

    Node *h1 = head;
    Node *mid = midPoint(head);
    Node *h2 = mid->next;
    mid->next = NULL;
   
    Node *r1 = mergeSort(h1);
    Node *r2 = mergeSort(h2);

    Node *rh = merge(r1, r2);
    return rh;
}