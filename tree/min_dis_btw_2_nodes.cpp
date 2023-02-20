    int ans = 0;
    int getDis(Node* root,int a,int b)
    {
        if(root == NULL)return 0;
        int sum = 0;
        
        if(a == root->data)sum++;
        if(b == root->data)sum++;
        
        int lh = getDis(root->left,a,b);
        int rh = getDis(root->right,a,b);
    
        if(sum > 0 && (lh > 0 || rh > 0) || (lh > 0 && rh > 0))
        {
            ans = (lh+rh);
            return -1;
        }
        
        if(lh > 0)return lh + 1;
        if(rh > 0)return rh + 1;
        return sum;
    }
    
    int findDist(Node* root, int a, int b) {
        getDis(root,a,b);
        return ans;
    }