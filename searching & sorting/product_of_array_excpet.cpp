class Solution {
public:
    int getProducts(vector<int>& nums,int prev,int index)
    {
        if(index == nums.size())return 1;
        int x = getProducts(nums,prev*nums[index],index+1);
        int s = x*nums[index];
        nums[index] = prev*x;
        return s;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        getProducts(nums,1,0);
        return nums;
    }
};