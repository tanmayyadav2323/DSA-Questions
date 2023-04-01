class Solution 
{
    public:
    static bool comp(Job j1, Job j2)
    {
       int p1 = j1.profit;
       int p2 = j2.profit;
       
       if(p1 == p2)return j1.dead>j2.dead;
       return p1>p2;
    }
    
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        int count = 0;
        int profit = 0;
        vector<int>v(n,-1);
        sort(arr,arr+n,comp);
        
        for(int i = 0; i<n ; i++)
        {
            for(int j = min(arr[i].dead,n)-1;j>=0 ; j--)
            {
               if(v[j] == -1)
               {
                   v[j]=1;
                   profit+=arr[i].profit;
                   count++;
                   break;
               }
            }
        }
        
        return {count,profit};
    } 
};