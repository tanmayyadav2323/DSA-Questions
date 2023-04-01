class Solution {
public:
    vector<int> getLargestBst(TreeNode* root)
    {
        if(root == NULL)return {INT_MAX,INT_MIN,0};

        vector<int> lh = getLargestBst(root->left);
        vector<int> rh = getLargestBst(root->right);

        if(lh[1] < root->val && rh[0] > root->val)
        {
            return {min(lh[0],root->val),max(rh[1],root->val),lh[2]+rh[2]+1};
        }

        return {INT_MIN,INT_MAX,max(lh[2],rh[2])};
    }

    int largestBSTSubtree(TreeNode* root) {
       return getLargestBst(root)[2];
    }
};