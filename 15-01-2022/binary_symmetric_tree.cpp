    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q)
        {
            if(p->val == q->val)return isSameTree(p->left,q->right) && isSameTree(p->right,q->left);
            else return false;
        }
        else if((p && !q) || (!p && q))return false;
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root,root);
    }