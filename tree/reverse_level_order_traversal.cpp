class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
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

            for(int i = 0; i<(vec.size()/2); i++)
            {
                swap(vec[i],vec[vec.size()-i-1]);
            }
        }

        return vec;
    }
};

class Solution {
public:
    void levelOrder(vector<vector<int>>&v , int level,TreeNode* root)
    {
        if(root == NULL)return;
        if(v.size() < level)
        {
            v.push_back({});
        }
        v[level-1].push_back(root->val);
        levelOrder(v,level+1,root->left);
        levelOrder(v,level+1,root->right);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>v;
        levelOrder(v,1,root);
        reverse(v.begin(),v.end());
        return v;
    }
};