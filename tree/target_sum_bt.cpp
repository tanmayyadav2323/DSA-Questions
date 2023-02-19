class Solution {
public:
    int helper(TreeNode* root,long long sum, map<long long,int>m,int target)
    {
        if(root == NULL)return 0;
        int count = 0;
        sum+=root->val;
        if(target == sum)count++;
        if(m.find(sum-target) != m.end())count+=m[sum-target];
        m[sum]++;
        return count + helper(root->left,sum,m,target) + helper(root->right,sum,m,target);
    }

    int pathSum(TreeNode* root, int targetSum) {
        map<long long,int>m ={};
        return helper(root,0,m,targetSum);
    }
};