class Solution
{
public:
    void getInorder(vector<int>&v, Node* root)
    {
        if(root == NULL)return;
        getInorder(v,root->left);
        v.push_back(root->data);
        getInorder(v,root->right);
    }
    
    int countPairs(Node* root1, Node* root2, int x)
    {
        vector<int>v1,v2;
        
        getInorder(v1,root1);
        getInorder(v2,root2);
        
        int i = 0;
        int j = v2.size()-1;
        int count = 0;
        while(i < v1.size() && j >= 0){
            int sum = v1[i] + v2[j];
            if(sum == x) count++, i++, j--;
            else if(sum < x) i++;
            else j--;
        }
        
        return count;
    }
};