class Solution
{
    TreeNode *head, *root3;

public:
    void makeTree(TreeNode *ele)
    {
        ele->right = NULL;
        ele->left = NULL;
        if (!root3)
            root3 = head = ele;
        else
        {
            root3->right = ele;
            root3 = root3->right;
        }
    }

    TreeNode *increasingBST(TreeNode *root)
    {
        if (root != NULL)
        {
            increasingBST(root->left);
            TreeNode *rt = root->right;
            makeTree(root);
            increasingBST(rt);
        }
        return head;
    }
};
