    vector<int> candyStore(int candies[], int N, int K)
    {
        sort(candies,candies+N);
        
        int i,j;
        i = 0;
        j = N;
        
        int minAmount = 0;
        int maxAmount = 0;
        
        while(i<j)
        {
            minAmount += candies[i];
            maxAmount += candies[N-i-1];
            j-=K;
            i++;
        }
        
        return {minAmount,maxAmount};
    }