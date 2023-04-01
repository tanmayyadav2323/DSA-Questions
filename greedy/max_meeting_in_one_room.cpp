class Triplet{
public:
    int start;
    int end;
    int index;
    
    Triplet(int u,int v,int i)
    {
        start = u;
        end = v;
        index = i;
    };
};

class Comp
{
public:
    bool operator()(Triplet &a,Triplet &b)
    {
        if(a.end == b.end)a.start>b.start;
        return a.end< b.end;
    }
};

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<Triplet>vec;
        
        for(int i = 0; i<N; i++)
        {
            vec.push_back(Triplet(S[i],F[i],i+1));
        }
        
        Comp comp;
        sort(vec.begin(),vec.end(),comp);
        
        int prev = vec[0].end;
        vector<int>ans;
        ans.push_back(vec[0].index);
        
        for(int i = 1; i<N; i++)
        {
            if(prev < vec[i].start)
            {
                ans.push_back(vec[i].index);
                prev = vec[i].end;
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};