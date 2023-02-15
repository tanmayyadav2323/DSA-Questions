class Solution {
public:
    void flatten(TreeNode* root) {
        
        while(root)
        {
            TreeNode* left = root->left;
            TreeNode* right = root->right;

            if(left)
            {
                while(left->right)
                {
                    left=left->right;
                }
                left->right=right;
                root->right=root->left;
                root->left = NULL;
            }

            root=root->right;
        }
    }
};