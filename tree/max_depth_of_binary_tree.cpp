class Solution {
public:
    int maxDepth(TreeNode* root) {
        int level = 0;
        
        if(root)
        {
            queue<TreeNode*>q;
            q.push(root);

            while(q.empty() == false)
            {
                level++;
                int size = q.size();
                while(size--)
                {
                    TreeNode* node = q.front();q.pop();
                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
            }
        }

        return level;
    }
};