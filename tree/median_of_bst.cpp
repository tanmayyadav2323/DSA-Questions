int calSize(Node* root)
{
    if(root == NULL)return 0;
    return calSize(root->left) + calSize(root->right)+1;
}


void getMedian(Node* root,bool even,int& size,int& n1, int& n2)
{
    if(root == NULL)return;
    getMedian(root->left,even,size,n1,n2);
    size--;
    if(size == 0)n1=root->data;
    if(size == 1 && even)n2 = root->data;
    getMedian(root->right,even,size,n1,n2);
}

float findMedian(struct Node *root)
{
    bool even = true;
    int size = calSize(root);
    if(size%2 != 0)even = false;
    int n1,n2;
    size/=2;
    size++;
    getMedian(root,even,size,n1,n2);
    if(even)return (n1+n2)/2.0;
    return n1;
}