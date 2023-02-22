class Solution {
public:
    int getSmallest(TreeNode* root,int& k)
    {
        if(root == NULL)return -1;
        int lh = getSmallest(root->left,k);
        if(lh >= 0)return lh;
        k--;
        if(k == 0)return root->val;
        return getSmallest(root->right,k);
    }

    int kthSmallest(TreeNode* root, int k) {
        return getSmallest(root,k);
    }
};