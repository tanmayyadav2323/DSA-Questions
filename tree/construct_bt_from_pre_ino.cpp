class Solution {
public:
    TreeNode* createTree(vector<int>& preorder, 
        vector<int>& inorder,int low,int high,int& k)
    {
        if(low>high)return NULL;
        int index = -1;

        for(int i = low; i<=high ; i++)if(preorder[k] == inorder[i]){index = i;break;}

        TreeNode* node =  new TreeNode(preorder[k]); k++;
        node->left = createTree(preorder,inorder,low,index-1,k);
        node->right = createTree(preorder,inorder,index+1,high,k);

        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int k = 0;
        return createTree(preorder,inorder,0,preorder.size()-1,k);
    }
};


class Solution {
public:
    TreeNode* createTree(vector<int>& preorder, 
        map<int,int>&inorderMap,int low,int high,int& k)
    {
        if(low>high)return NULL;
        int index = inorderMap[preorder[k]];
        TreeNode* node =  new TreeNode(preorder[k]); k++;
        node->left = createTree(preorder,inorderMap,low,index-1,k);
        node->right = createTree(preorder,inorderMap,index+1,high,k);

        return node;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inorderMap;

        for(int i= 0 ; i<inorder.size();i++)
        {
            inorderMap[inorder[i]]=i;
        }

        int k = 0;
        return createTree(preorder,inorderMap,0,preorder.size()-1,k);
    }
};