class Solution{
  public:
    pair<int,int> calSum(Node* root)
    {
        if(root == NULL)return {0,0};
        pair<int,int> l = calSum(root->left);
        pair<int,int> r = calSum(root->right);
        pair<int,int> ans;
        ans.first = root->data + l.second + r.second;
        ans.second = max(l.first,l.second) + max(r.first,r.second);
        
        return ans;

    }
    
    int getMaxSum(Node *root) 
    {
       pair<int,int> ans = calSum(root);
        return max(ans.first,ans.second);
    }
};