class Solution{
public:
    int minimumDays(int S, int N, int M){
        int req = S*M;
        int shopDays = S - S/7;
        int daysForReq = ceil((double)req/N);
        
        if(daysForReq > shopDays)return -1;
        return daysForReq;
    }
};