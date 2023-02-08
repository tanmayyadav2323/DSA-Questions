bool isCircular(Node *head)
{
    Node* slow = head;
    Node* fast = head;
    
    do
    {
        fast=fast->next;
    }
    while(fast && slow != fast);
    
    return slow == fast;
}