class Solution 
{
    public:
	int minSwaps(vector<int>&nums)
	{
	    int size = nums.size();
	    vector<pair<int,int>>vec(size);
	    
	    for(int i = 0; i<size ; i++)
	    {
	        vec[i] = {nums[i],i};
	    }
	    
	    sort(vec.begin(),vec.end());
	    int count = 0;
	    
	    for(int i = 0; i<size ; i++)
	    {
	        if(i != vec[i].second)
	        {
	            swap(vec[i],vec[vec[i].second]);
	            i--;
	            count++;
	        }
	    }
	    
	    return count;
	}
};