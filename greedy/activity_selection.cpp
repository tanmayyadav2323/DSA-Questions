    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int>>vec;
        
        for(int i = 0; i<n ; i++)
        {
            vec.push_back({end[i],start[i]});
        }
        
        sort(vec.begin(),vec.end());
        
        int count = 1;
        int prev = vec[0].first;
        for(int i = 1; i<n ; i++)
        {
            if(prev < vec[i].second){
                count++;
                prev = vec[i].first;
            }
            
        }
        
        return count;
    }