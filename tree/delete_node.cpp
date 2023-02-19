class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)return NULL;
        if(root->val > key)root->left= deleteNode(root->left,key);
        else if(root->val < key)root->right= deleteNode(root->right,key);
        else
        {
            if(root->left == NULL)return root->right;
            if(root->right == NULL)return root->left;

            TreeNode* temp = root->left;
            while(temp->right)temp=temp->right;
            swap(temp->val,root->val);
            root->left = deleteNode(root->left,temp->val);
        }
        return root;
    }
};