    vector<int> inorderTraversal(TreeNode* root) {
        if(root)
        {
            inorderTraversal(root->left);
            vec.push_back(root->val);
            inorderTraversal(root->right);
        }
        return vec;
    }