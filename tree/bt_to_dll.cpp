class Solution
{
    public: 
    Node* getDLL(Node* root,Node*& prev,Node*& newHead)
    {
        if(root == NULL)return NULL;
        root->left = getDLL(root->left,prev,newHead);
        if(prev)
        {
            prev->right = root;
            root->left = prev;
        }
        else 
        {
            newHead = root;
        }
        prev = root;
        getDLL(root->right,prev,newHead);
        return root;
    }
    
    Node * bToDLL(Node *root)
    {
        Node* prev = NULL;
        Node* newHead = NULL;
        getDLL(root,prev,newHead);
        return newHead;
    }
};


class Solution
{
    public: 
    Node * bToDLL(Node *root)
    {
        stack<Node*>stk;
        Node* prev = NULL;
        Node* head;
        
        while(stk.empty() == false || root)
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            Node* node = stk.top();stk.pop();
            if(prev)
            {
                prev->right = node;
                node->left = prev;
            }
            else head = node;
            prev=node;
            root=node->right;
        }
        
       return head; 
    }
};