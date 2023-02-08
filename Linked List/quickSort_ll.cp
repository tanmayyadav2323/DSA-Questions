node* partition(node* head, node* tail)
{
    node* j = head;
    int pivot = j->data;
    node* i = head;
    
    while(j != tail)
    {
        if(pivot > j->data)
        {
            i = i->next;
            swap(i->data,j->data);
        }
        j = j->next;
    }
    
    swap(head->data,i->data);
    return i;
}

node* sort(node* head, node* tail)
{
    if(head != tail)
    {
        node* mid = partition(head,tail);
        node* lt = sort(head,mid);
        node* rt = sort(mid->next,tail);
    }
    return head;
}


void quickSort(struct node **headRef) {
    sort(*headRef,NULL);
}