class Solution {
public:
    TreeNode* getTree(string s, int& index)
    {
        if(index>=s.size())return NULL;
        int neg = 1;
        if(s[index] == '-')
        {
            index++;
            neg = -1;
        }
        int val = 0;
        while(s[index] >= '0' && s[index] <='9')
        {
            val = val*10 + (int(s[index])-'0');
            index++;
        }
        TreeNode* node = new TreeNode(neg*val);
        if(s[index] == '('){
            index++;
            node->left = getTree(s,index);
        }
        if(s[index] == '('){
            index++;
            node->right = getTree(s,index);
        }
        index++;
        return node;
    }

    TreeNode* str2tree(string s) {
        int index = 0;
        return getTree(s,index);
    }
};