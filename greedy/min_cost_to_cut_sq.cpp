    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){

        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        int i = 0;
        int j = 0;
        int cost = 0;

        
        int hz = 1;
        int vc = 1;
        
        
        while(i<M && j<N)
        {
            if(X[i] > Y[j])
            {
                cost += X[i]*hz;
                vc++;
                i++;
            }
            else
            {
                cost += Y[j]*vc;
                hz++;
                j++;
            }
        }
        
        while(i<M)
        {
            cost += X[i]*hz;
            i++;
        }
        
        while(j<N)
        {
            cost += Y[j]*vc;
            j++;
        }
        
        return cost;
    }