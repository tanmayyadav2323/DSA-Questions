class Solution {
  public:
    int getTree(Node* node)
    {
        if(node == NULL)return 0;
        int lh = getTree(node->left);
        int rh = getTree(node->right);
        int data = node->data+lh+rh;
        node->data = lh+rh;
        return data;
    }
  
    void toSumTree(Node *node)
    {
        int x = node->data;
        node->data = getTree(node)-x;
    }
};