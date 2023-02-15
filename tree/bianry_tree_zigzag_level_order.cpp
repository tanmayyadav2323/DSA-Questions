class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool reverse = false;
        vector<vector<int>>vec;

        if(root)
        {
            queue<TreeNode*>q;
            q.push(root);

            while(q.empty() == false)
            {
                int size = q.size();
                vector<int>v(size);

                for(int i = 0; i<size ; i++)
                {
                    TreeNode* node = q.front();q.pop();
                    if(reverse)v[size-i-1]=node->val;
                    else v[i]=node->val;

                    if(node->left)q.push(node->left);
                    if(node->right)q.push(node->right);
                }
                vec.push_back(v);
                reverse =!reverse;
            }
        }

        return vec;
    }
};