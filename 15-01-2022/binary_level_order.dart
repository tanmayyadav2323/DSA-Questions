    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return {};
        q.push(root);
        q.push(NULL);
        
        while(!q.empty())
        {
            x = q.front();
            q.pop();
            if(x == NULL)
            {
                vec.push_back(v);
                v={};
                if(!q.empty())q.push(NULL);
            }
            else
            {
                if(x->left != NULL)q.push(x->left);
                if(x->right !=  NULL)q.push(x->right);
                v.push_back(x->val);
            }
        }
        return vec;
    }