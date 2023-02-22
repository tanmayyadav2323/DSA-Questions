class Solution{
  public:
    void traverseTree(vector<int>& vec,Node* root)
    {
        if(root == NULL)return;
        traverseTree(vec,root->left);
        vec.push_back(root->data);
        traverseTree(vec,root->right);
    }
    
    Node* setTreeVal(vector<int>& vec, Node* root,int& index)
    {
        if(root == NULL)return NULL;
        root->left = setTreeVal(vec,root->left,index);
        root->data = vec[index++];
        root->right = setTreeVal(vec,root->right,index);
        return root;
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        vector<int>vec;
        int index = 0;
        traverseTree(vec,root);
        sort(vec.begin(),vec.end());
        return setTreeVal(vec,root,index);
    }

};