    int buyMaximumProducts(int n, int k, int price[]){
        vector<pair<int,int>>vec;
        
        for(int i = 0; i<n  ; i++)
        {
            vec.push_back({price[i],i+1});
        }
        
        sort(vec.begin(),vec.end());
        
        int count = 0;
        for(int i = 0; i<n ; i++)
        {
            if(k>=vec[i].first)
            {
                int stocks = k/(vec[i].first);
                int mn = min(stocks,vec[i].second);
                k -= mn*(vec[i].first);
                count+=mn;
            }
            else
            {
                break;
            }
        }
        
        return count;
    }