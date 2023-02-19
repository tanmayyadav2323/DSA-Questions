    void getLongestPathSum(int sum,int level,int& curMax,int& maxLevel,Node* root)
    {
        if(root)
        {
            sum += root->data;
            if(level == maxLevel)
            {
                curMax = max(curMax,sum);
            }
            if(level > maxLevel)
            {
                curMax = sum;
                maxLevel=level;
            }
            getLongestPathSum(sum,level+1,curMax,maxLevel,root->left);
            getLongestPathSum(sum,level+1,curMax,maxLevel,root->right);
        }
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int curMax = 0;
        int maxLevel = 0;
        
        getLongestPathSum(0,0,curMax,maxLevel,root);
        
        return curMax;
    }