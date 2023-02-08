class Solution {
public:
    bool isFeasible(int k,vector<int>& stalls,int mid)
    {
        int count = 1;
        int diff = stalls[0];
        
        for(int i = 1; i<stalls.size() ; i++)
        {
            int x = stalls[i];
            if(x-diff >= mid)
            {
                count++;
                diff = x;
            }
        }
        
        return count >= k;
    }

    int solve(int n, int k, vector<int> &stalls) {
        sort(stalls.begin(),stalls.end());
        
        int low = 1;
        int high = stalls[n-1]-stalls[0];
        int res = 0;
        int mid = -1;
        
        while(low <= high)
        {
            mid = (high+low)/2;
            
            if(isFeasible(k,stalls,mid))
            {
                res = mid;
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        
        return res;
    }