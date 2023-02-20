Node* getPre(Node* root)
{
    while(root->right)root=root->right;
    return root;
}

Node* getSucc(Node* root)
{
    while(root->left)root=root->left;
    return root;
}


void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    
    while(root)
    {
        if(root->key == key)
        {
            if(root->left)pre = getPre(root->left);
            if(root->right)suc = getSucc(root->right);
            return;
        }
        
        if(root->key > key) 
        {
            suc = root;
            root=root->left;
        }
        else
        {
            pre = root;
            root=root->right;
        }
    }

}