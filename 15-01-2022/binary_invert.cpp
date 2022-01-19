    TreeNode* invertTree(TreeNode* root) {
        if(!root)return NULL;
        invertTree(root->left);
        invertTree(root->right);
        TreeNode*z=root->left;
        root->left=root->right;
        root->right=z;
        return root;
    }