class Solution{
  public:
    bool isLeaf(Node* root)
    {
        return (root->left == NULL && root->right == NULL);
    }
    bool check(Node *root)
    {
        int h = -1;
        
        if(root)
        {
            queue<pair<Node*,int>>q;
            q.push({root,0});
            
            while(q.empty() == false)
            {
                Node* node = q.front().first;
                int level = q.front().second;
                q.pop();
                
                if(isLeaf(node))
                {
                    if(h == -1)h=level;
                    if(h != level)return false;
                }
                
                if(node->left)q.push({node->left,level+1});
                if(node->right)q.push({node->right,level+1});
            }
        }
        
        return true;
    }
};