Node* reverseDLL(Node * head)
{
    Node* cur = head->next;
    Node* prev = head;
    prev->next = NULL;
    Node* next;
    
    while(cur)
    {
        next = cur->next;
        cur->next = prev;
        prev->prev = cur;
        cur->prev = next;
        prev=cur;
        cur = next;
    }
    
    return prev;
}