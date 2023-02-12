class Solution
{
    public:
        bool isFeasible(int mid,int n)
        {
            int num = 0;
            int temp;
            
            while(mid > 1)
            {
                temp = mid/5;
                num += temp;
                mid = temp;
            }
            
            return num >= n;
        }
    
        int findNum(int n)
        {
            int low = 1;
            int high = 5*n;
            int mid;
            int res = 0;
            
            while(low <= high)
            {
                mid = (low+high)/2;
                
                if(isFeasible(mid,n))
                {
                    res = mid;
                    high = mid-1;
                }
                else
                {
                    low = mid + 1;
                }
            }
            
            return res;
        }