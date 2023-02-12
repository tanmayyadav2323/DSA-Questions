class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rowEnd = matrix.size();

        int i = 0;
        int j = matrix[0].size()-1;

        while(i<rowEnd && j>=0)
        {
            if(matrix[i][j] == target)return true;
            if(matrix[i][j] < target)i++;
            else j--;
        }

        return false;
    }
};