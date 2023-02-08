class Solution
{
    public:
    Node* rec(Node* head)
    {
       if(head == NULL || head->next == NULL)return head;
       head->next = rec(head->next);
       
       if(head->data < head->next->data)return head->next;
       return head;
    }
    
    
    Node *compute(Node *head)
    {
        return rec(head);
    }
    
};