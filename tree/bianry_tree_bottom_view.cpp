class Solution {
  public:
    vector <int> bottomView(Node *root) {
        map<int,int>m;
        vector<int>vec;
        
        if(root)
        {
            queue<pair<Node*,int>>q;
            q.push({root,0});
            
            while(q.empty() == false)
            {
                Node* node = q.front().first;
                int i = q.front().second;
                q.pop();
                
                m[i] = node->data;
                if(node->left)q.push({node->left,i-1});
                if(node->right)q.push({node->right,i+1});
            }
            
            for(pair<int,int> v: m)
            {
                vec.push_back(v.second);
            }
        }
        
        return vec;
    }
};