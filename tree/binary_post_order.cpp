class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>v;
        stack<TreeNode*> stk;

        while(stk.empty() == false || root)
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }

            TreeNode* node = stk.top();
            if(node->right)
            {
                root=node->right;
            }
            else
            {
                v.push_back(node->val);stk.pop();
                while(!stk.empty() && node == stk.top()->right)
                {
                   v.push_back(stk.top()->val);
                   node=stk.top();
                   stk.pop();
                }
            }
        }
        return v;
    }
};