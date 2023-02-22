class Solution {
public:
    void traverseTree(TreeNode* root , vector<int>& vec)
    {
        if(root == NULL)return;
        traverseTree(root->left,vec);
        vec.push_back(root->val);
        traverseTree(root->right,vec);
    }

    TreeNode* buildTree(vector<int>&vec,int low,int high)
    {
        if(low>high)return NULL;
        int mid = (low+high)/2;
        TreeNode* node = new TreeNode(vec[mid]);
        node->left = buildTree(vec,low,mid-1);
        node->right = buildTree(vec,mid+1,high);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int>vec;
        traverseTree(root,vec);
        sort(vec.begin(),vec.end());
        return buildTree(vec,0,vec.size()-1);
    }
};