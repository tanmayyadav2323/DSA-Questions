class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        
        int mx,mn,ans;
        ans = arr[n-1]-arr[0];
        
        for(int i = 1; i<n ; i++)
        {
            mn = min(arr[0]+k,arr[i]-k);
            mx = max(arr[i-1]+k,arr[n-1]-k);
            
            if(arr[i]-k>=0)
            {
                ans = min(ans,mx-mn);
            }
        }
        
        return ans;
    }
};