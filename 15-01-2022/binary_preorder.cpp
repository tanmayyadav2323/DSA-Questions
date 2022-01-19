    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)return vec;
        vec.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return vec;
    }