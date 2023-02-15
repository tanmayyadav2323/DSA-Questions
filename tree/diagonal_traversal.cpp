void helper(Node* root,int pos,int level,map<int,vector<int>>&m)
{
    if(root)
    {
        m[abs(pos-level)].push_back(root->data);
        helper(root->left,pos-1,level+1,m);
        helper(root->right,pos+1,level+1,m);
    }
}

vector<int> diagonal(Node *root)
{
    map<int,vector<int>>m;
    vector<int>vec;
    int pos = 0;
    int level = 0;
    
    helper(root,pos,level,m);
    
    for(auto it : m)
    {
        for(int v : it.second)
        {
            vec.push_back(v);
        }
    }
    
    return vec;
    
}


vector<int> diagonal(Node *root)
{
    vector<int>v;
    
    if(root)
    {
        queue<Node*>q;
        q.push(root);
        
        while(q.empty() == false)
        {
            Node* node = q.front();q.pop();
    
            while(node)
            {
                v.push_back(node->data);
                if(node->left)q.push(node->left);
                node=node->right;
            }
        }
    }
    
    return v;
    
}