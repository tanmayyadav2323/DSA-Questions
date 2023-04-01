class Solution
{
    static bool comp(Item p1, Item p2)
    {
        return ((double)p1.value/p1.weight) > ((double)p2.value/p2.weight);
    }
    
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        sort(arr,arr+n,comp);
        for(int i = 0; i<n ; i++)
        {
            if(W >= arr[i].weight)
            {
                ans += arr[i].value;
                W-=arr[i].weight;
            }
            else
            {
                ans += (double(arr[i].value)/arr[i].weight)*W;
                break;
            }
        }
        
        return ans;
    }
        
};