class comp{
    public:
     bool operator()(Node* a, Node* b){
         return a->data > b->data;
     }
};

Node *sortedDll(Node *head, int k)
{
    priority_queue<Node*,vector<Node*>,comp>pq;
    Node* newHead,*newPtr;
    newHead=NULL;

    for(int i = 0; i<=k ; i++)
    {
        pq.push(head);
        head=head->next;
    }

    while(pq.empty() == false)
    {
        Node* node = pq.top();pq.pop();
        node->next=NULL;
        node->prev=NULL;
        
        if(newHead == NULL){
            newHead=node;
            newPtr=node;
        }
        else 
        {
            newPtr->next = node;
            node->prev=newPtr;
            newPtr =  node;
        }

        if(head)
        {
            pq.push(head);
            head=head->next;
        }
    }

    return newHead;

}

