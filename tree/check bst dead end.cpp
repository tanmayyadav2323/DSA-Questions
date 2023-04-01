bool checkDeadEnd(Node* root,int mn,int mx)
{
    if(root == NULL)return false;
    if(mn == root->data && mx==root->data)return true;
    if(checkDeadEnd(root->left,mn,root->data-1))return true;
    if(checkDeadEnd(root->right,root->data+1,mx))return true;
    return false;
}

bool isDeadEnd(Node *root)
{
    return checkDeadEnd(root,1,INT_MAX);
}