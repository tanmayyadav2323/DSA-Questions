class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>vec;
        
        for(int i = 0; i<nums.size()-2;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            int j = i+1;
            int k = nums.size()-1;
            
            while(j<k)
            {
                if(nums[j]+nums[k] == -nums[i])
                {
                    vec.push_back({nums[j],nums[k],nums[i]});
                    k--;
                    j++;
                    while(j<k && nums[k] == nums[k+1])k--;
                    while(j<k && nums[j] == nums[j-1])j++;
                }
                else if(nums[j]+nums[k] > -nums[i])k--;
                else j++;
            }
        }
        
        return vec;
    }
};