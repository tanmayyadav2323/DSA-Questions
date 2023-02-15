class Solution {
public:
    string getDuplicates(TreeNode* root, unordered_map<string,int>&m,vector<TreeNode*> & res)
    {
        if(root == NULL)return "";
        string s = "("+to_string(root->val)+getDuplicates(root->left,m,res)+")"
                    +getDuplicates(root->right,m,res)+")";
        m[s]++;
        if(m[s] == 2)res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<string,int>m;
        getDuplicates(root,m,res);
        return res;
    }
};

class Solution {
public:
    string getDuplicates(TreeNode* root, unordered_map<string,int>&triplet
                ,unordered_map<int,int>&m
                ,vector<TreeNode*> & res)
    {
        if(root == NULL)return "";
        string s = "("+to_string(root->val)+getDuplicates(root->left,triplet,m,res)+")"
                    +getDuplicates(root->right,triplet,m,res)+")";
        if(triplet.find(s) == triplet.end())
        {
            triplet[s]=triplet.size()+1;
        }
        int id = triplet[s];
        m[id]++;
        if(m[id] == 2)res.push_back(root);
        return s;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*>res;
        unordered_map<int,int>m;
        unordered_map<string,int>tripletID;
        getDuplicates(root,tripletID,m,res);
        return res;
    }
};