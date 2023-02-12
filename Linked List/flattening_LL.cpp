Node* merge(Node* listA, Node* listB)
{
    Node* head;
    Node* ptr;
    
    if(listA->data < listB->data)
    {
        head=ptr=listA;
        listA=listA->bottom;
    }
    else
    {
        head=ptr=listB;
        listB=listB->bottom;
    }
    ptr->bottom=NULL;
    
    while(listA && listB)
    {
        if(listA->data < listB->data)
        {
            ptr->bottom = listA;
            ptr=listA;
            listA=listA->bottom;
        }
        else
        {
            ptr->bottom = listB;
            ptr=listB;
            listB=listB->bottom;
        }
        ptr->bottom=NULL;
    }
    
    if(listA)ptr->bottom=listA;
    else ptr->bottom = listB;
    
    return head;
}


Node *flatten(Node *head)
{
    while(head && head->next)
    {
        Node* next = head->next->next;
        head = merge(head,head->next);
        head->next = next;
    }
    
    return head;
}