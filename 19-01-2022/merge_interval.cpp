
class Solution
{
    vector<vector<int>> vec;

public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0];
        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {
            if (end > intervals[i][1])
                ;
            else if (end >= intervals[i][0])
                end = intervals[i][1];
            else
            {
                vec.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        vec.push_back({start, end});
        return vec;
    }
};