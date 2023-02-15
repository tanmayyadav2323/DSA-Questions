class Solution {
public:
    int getSum(TreeNode* node,int& res)
    {
        if(node  == NULL)return 0;
        int lh = max(0,getSum(node->left,res));
        int rh = max(0,getSum(node->right,res));
        res = max(res,lh+rh+node->val);
        return max(lh,rh)+node->val;
    }

    int maxPathSum(TreeNode* root) {
        if(root == NULL)return 0;
        int res = root->val;
        getSum(root,res);
        return res;
    }
};