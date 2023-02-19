class Solution {
public:
    int findAncestor(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans)
    {
        if(root == NULL)return 0;
        int sum = 0;
        if(p == root)sum+=1;
        if(q == root)sum+=1;
        sum += findAncestor(root->left,p,q,ans);
        sum += findAncestor(root->right,p,q,ans);
        if(sum == 2)
        {
            ans = root;
            return 1;
        }
        return sum;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        findAncestor(root,p,q,ans);
        return ans;
    }
};