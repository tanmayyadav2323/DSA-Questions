class Solution{
    public:
    int minSubset(vector<int> &Arr,int N){
        sort(Arr.begin(),Arr.end());
        
        int j = N;
        long long int sumR = 0;
        long long int sumL = 0;
        
        for(int i =0; i<N; i++)sumL+=Arr[i];
        
        while(sumL>=sumR)
        {
            j--;
            sumL-=Arr[j];
            sumR+=Arr[j];
        }
        
        return N-j;
    }
};