class Solution {
public:
    int getDiameter(TreeNode* root,int& res)
    {
        if(root == NULL)return 0;
        int lh = getDiameter(root->left,res);
        int rh = getDiameter(root->right,res);
        res = max(res,lh+rh);
        return max(lh,rh)+1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        getDiameter(root,res);
        return res;
    }
};