class Solution {
public:
    bool checkSymmetry(TreeNode* a, TreeNode* b)
    {
        if(a && !b || b && !a)return false;
        if(!a && !b)return true;
        return a->val == b->val 
            && checkSymmetry(a->left,b->right) 
            && checkSymmetry(a->right,b->left);
    }

    bool isSymmetric(TreeNode* root) {
        return checkSymmetry(root->left,root->right);
    }
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL || !root->left && !root->right)return true;
        if(!root->left && root->right || !root->right && root->left)return false;

        bool check = true;
        queue<pair<TreeNode*,TreeNode*>>q;
        q.push({root->left,root->right});

        while(q.empty() == false)
        {
            TreeNode* nodeA = q.front().first;
            TreeNode* nodeB = q.front().second;q.pop();

            if(nodeA->val != nodeB->val)
            {
                check = false;break;
            }

            if(nodeA->left && nodeB->right)q.push({nodeA->left,nodeB->right});
            if(nodeA->right && nodeB->left)q.push({nodeA->right,nodeB->left});

            if(nodeA->left && !nodeB->right || !nodeA->left && nodeB->right)
            {
                check = false;break;
            }

            if(nodeA->right && !nodeB->left || !nodeA->right && nodeB->left)
            {
                check = false;break;
            }
        }

        return check;
    }
};