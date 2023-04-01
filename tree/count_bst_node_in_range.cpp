class Solution{
public:
    void traversal(Node* root,int l,int h,int& count)
    {
        if(root == NULL)return;
        if(root->data >= l && root->data <=h)count++;
        traversal(root->left,l,h,count);
        traversal(root->right,l,h,count);
    }
    
    int getCount(Node *root, int l, int h)
    {
        int count = 0;
        traversal(root,l,h,count);
        return count;
    }
};