bool hasPathSum(TreeNode *root, int targetSum, int curr = 0)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
        return (curr + root->val == targetSum);
    return (hasPathSum(root->left, targetSum, curr + root->val) || hasPathSum(root->right, targetSum, curr + root->val));
}