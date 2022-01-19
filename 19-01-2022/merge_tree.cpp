class Solution
{
public:
    TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
    {
        if (!root1 && !root2)
            return NULL;
        else if (!root1)
            return root2;
        else if (!root2)
            return root1;
        TreeNode *root3 = new TreeNode();
        root3->val = root1->val + root2->val;
        root3->left = mergeTrees(root1->left, root2->left);
        root3->right = mergeTrees(root1->right, root2->right);
        return root3;
    }
};
