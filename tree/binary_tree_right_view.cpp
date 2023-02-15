class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        int maxLevel = -1;
        int level = 0;
        vector<int>v;

        if(root)
        {
            queue<TreeNode*>q;
            q.push(root);

            while(q.empty() == false)
            {
                int size = q.size();

                for(int i = 0; i<size ; i++)
                {
                    TreeNode* node= q.front();q.pop();
                    if(level > maxLevel)
                    {
                        v.push_back(node->val);
                        maxLevel = level;
                    }
                    if(node->right)q.push(node->right);
                    if(node->left)q.push(node->left);
                }
                level++;
            }
        }

        return v;
    }
};

class Solution {
public:
    void getView(TreeNode* root, int level,int& maxLevel,vector<int>&v)
    {
        if(root == NULL)return;
        if(level > maxLevel)
        {
            v.push_back(root->val);
            maxLevel = level;
        }
        getView(root->right,level+1,maxLevel,v);
        getView(root->left,level+1,maxLevel,v);
    }

    vector<int> rightSideView(TreeNode* root) {
        int maxLevel = -1;
        vector<int>v;

        getView(root,0,maxLevel,v);
        return v;
    }
};