class Solution {
public:
    TreeNode* buildbst(vector<int>&preorder,int& index,int parent)
    {
        if(index >= preorder.size() || preorder[index] >= parent)return NULL;
        int key = preorder[index++];
        TreeNode* root = new TreeNode(key);
        root->left = buildbst(preorder,index,key);
        root->right = buildbst(preorder,index,parent);
        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index  = 0;
        return buildbst(preorder,index ,INT_MAX);
    }
};