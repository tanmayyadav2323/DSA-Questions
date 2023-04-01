class Solution{
public:
    int maxSum(int n){
        if(n==1)  return 1;
        return ((n*(n-1))/2 +n/2 -1);
    }
};