class Solution {
  public:
    int getMaxSumTree(Node* root,int& mxSum)
    {
        if(root == NULL)return 0;
        int lh = getMaxSumTree(root->left,mxSum);
        int rh = getMaxSumTree(root->right,mxSum);
        int sum = lh+rh+root->data;
        mxSum = max(mxSum,sum);
        return sum;
    }
    
    int findLargestSubtreeSum(Node* root)
    {
        int mxSum = INT_MIN;
        getMaxSumTree(root,mxSum);
        return mxSum;
    }
};