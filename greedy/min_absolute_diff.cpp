class Solution {
public:
    int nearestElement(vector<int>&v,int val){
      int closest = INT_MAX;
      int i = 0;
      int j = v.size()-1;

      while(i<=j)
      {
        int mid = (i+j)/2;
        closest = min(closest,abs(v[mid]-val));
        if(v[mid] == val)return 0;
        if(v[mid] < val)i=mid+1;
        else j = mid-1;
      }

      return closest;
    }

    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
      vector<int>v1 = nums1;
      sort(v1.begin(),v1.end());
      int maxDiff = INT_MIN;
      int value = -1;
      int index = -1;
      long long  int sum = 0;
      
      int mod = (1e9+7);
      
      for(int i = 0; i<nums1.size(); i++)
      {
          int diff = abs(nums1[i]-nums2[i]);
          int closeElement = nearestElement(v1,nums2[i]);

          if(diff > closeElement && maxDiff < diff-closeElement)
          {
            maxDiff = diff-closeElement;
            value = closeElement;
            index = i;
          }
      }

      for(int i = 0; i<nums1.size(); i++)
      {
          if(index == i){
              sum+=value;
          }
          else
          {
              sum += abs(nums1[i]-nums2[i]);
          }
          sum%=mod;
      }

      return sum%mod;
    };
};