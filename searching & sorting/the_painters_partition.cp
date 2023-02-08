class Solution
{
  public:
    bool isFeasible(int arr[],int k,long long mid,int n)
    {
        int count = 1;
        long long sum = 0;
        
        for(int i = 0; i<n ; i++)
        {
            sum+=arr[i];
            if(sum > mid)
            {
                sum = arr[i];
                count++;
            }
        }
        
        return count<=k;
    }
    
    
    long long minTime(int arr[], int n, int k)
    {
        int low = 0;
        long long high = 0;
        int res = 0;
        
        for(int i = 0; i<n ; i++)
        {
            low=max(low,arr[i]);
            high+=arr[i];
        }
        
        while(low<=high)
        {
            long long mid = (high-low)/2+low;
            if(isFeasible(arr,k,mid,n))
            {
                res = mid;
                high = mid-1;
                
            }
            else
            {
                low=mid+1;
            }
        }
        
        return res;
    
    }