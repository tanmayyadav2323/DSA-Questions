    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)return vec;
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        vec.push_back(root->val);
        return vec;  
    }