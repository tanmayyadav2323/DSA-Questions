class Solution{
  public:
    void getInorder(vector<int>&A,int n,int i,vector<int>&res)
    {
        if(i<n){
            getInorder(A,n,2*i+1,res);
            res.push_back(A[i]);
            getInorder(A,n,2*i+2,res);
        }
    }
    
    int minSwaps(vector<int>&A, int n){
        vector<int>res;
        getInorder(A,n,0,res);
        int count = 0;
        
        sort(A.begin(),A.end());
        unordered_map<int,int>m;
        
        for(int i = 0; i<A.size() ;i++)m[A[i]]=i;
        
        for(int i = 0; i<res.size() ; i++)
        {
            if(i != m[res[i]])
            {
                swap(res[i],res[m[res[i]]]);
                i--;
                count++;
            }
        }
        
        return count;
    }
    
    
};
