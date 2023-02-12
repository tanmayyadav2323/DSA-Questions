    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        Node* last = NULL;
        Node* first = head;
        vector<pair<int,int>>v;
        
        int sum = 0;
        
        while(head)
        {
            last = head;
            head=head->next;
        }
        
        while(first->data < last->data)
        {
            sum = last->data + first->data;
            
            if(sum == target)
            {
                v.push_back({first->data,last->data});
                first=first->next;
                last=last->prev;
            }
            else if(sum < target)
            {
                first = first->next;
            }
            else 
            {
                last = last->prev;
            }
        }
        
        return v;
    }