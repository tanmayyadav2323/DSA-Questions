int countTriplets(struct Node* head, int x) 
{ 
    set<int>s;
    int target;
    int count = 0;
    
    Node* ptr = head;
    
    while(ptr)
    {
        s.insert(ptr->data);
        ptr=ptr->next;
    }
    
    while(head)
    {
        ptr=head->next;
        
        while(ptr)
        {
            target=x-head->data-ptr->data;
            if(target<=ptr->data)break;
            else if(s.find(target) != s.end())count++;
            
            ptr=ptr->next;
        }
        
        head=head->next;
    }
    
    return count;
} 