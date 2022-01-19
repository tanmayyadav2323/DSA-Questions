class Solution
{
    int i = 0;
    int max, index;

public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return true;
        while (i < nums.size() && nums[i] != 0)
        {
            max = index = 0;
            for (int j = i; j <= i + nums[i]; j++)
            {
                if (j + nums[j] >= max)
                {
                    max = j + nums[j];
                    index = j;
                }
                if (j + nums[j] >= nums.size() - 1)
                    return true;
            }
            i = index;
        }
        return false;
    }
};