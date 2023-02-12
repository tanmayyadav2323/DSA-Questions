class Solution{   
public:
    int findMissing(int arr[], int n) {
        int low = 0;
        int high = n-1;
        int ap = (arr[n-1]-arr[0])/n;
        int target = 0;
        int mid = 0;
        
        while(low < high)
        {
            mid = (low+high)/2;
            target= arr[0]+ap*(mid);
            
            if(arr[mid] != target)high=mid;
            else low=mid+1;
        }
        
        return arr[0]+ap*(low);
    }
};