class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = matrix.size()-1;
        int colEnd = matrix[0].size()-1;
        vector<int>v;

        while(rowStart <= rowEnd && colStart <= colEnd)
        {
            for(int i = colStart ; i<=colEnd ; i++)
            {
                v.push_back(matrix[rowStart][i]);
            }
            rowStart++;

            for(int i = rowStart; i<rowEnd ; i++)
            {
                v.push_back(matrix[i][colEnd]);
            }

            
            if(rowStart <= rowEnd)
            {
                for(int i = colEnd; i>=colStart ; i--)
                {
                    v.push_back(matrix[rowEnd][i]);
                }
            }
            rowEnd--;
            colEnd--;

            if(colStart <= colEnd)
            {
                for(int i = rowEnd; i>=rowStart ; i--)
                {
                    v.push_back(matrix[i][colStart]);
                }
            }
            colStart++;
        }


        return v;
    }
};