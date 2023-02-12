class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>vec;

        if(root)
        {
            queue<TreeNode*>q;
            q.push(root);

            while(q.empty() == false)
            {
                int size = q.size();
                vector<int>v;
                while(size--)
                {
                    TreeNode* node = q.front();q.pop();
                    v.push_back(node->val);
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                vec.push_back(v);
            }
        }

        return vec;
    }
};