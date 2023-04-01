long long int maxSum(int arr[], int n)
{
    sort(arr,arr+n);
    int i = 0;
    int j = n-1;
    long long diff = 0;
    
    while(i<j)
    {
        diff += arr[j]-arr[i];
        diff += arr[j] - arr[i+1];
        i++;j--;
    }
    diff += arr[i]-arr[0];
    return diff;
    
}