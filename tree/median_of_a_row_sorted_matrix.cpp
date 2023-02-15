class Solution {
public:
    int getCount(int mid,vector<vector<int>>& grid)
    {
        int row = grid.size();
        int col = grid[0].size();
        int count = 0;

        for(int i  = 0; i<row ; i++)
        {
            for(int j = 0; j<col ; j++)
            {
                if(grid[i][j] > mid)break;
                count++;
            }
        }

        return count;
    }

    int matrixMedian(vector<vector<int>>& grid) {
        int low = INT_MAX;
        int high = INT_MIN;
        int row = grid.size();
        int col = grid[0].size();

        for(int i = 0; i<grid.size() ; i++)
        {
            low = min(low,grid[i][0]);
            high = max(high,grid[i][grid[0].size()-1]);
        }
    
        while(low < high)
        {
            int mid = (low+high)/2;
            int count = getCount(mid,grid);

            if(count<(row*col+1)/2)
            {
                low = mid+1;
            }
            else
            {
                high = mid;
            }

        }

        return low;
    }
};