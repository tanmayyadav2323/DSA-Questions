class Solution{   
public:
    string smallestNumber(int S, int D){
        string s = "";
        
        for(int i = 0; i<D; i++)
        {
            int rem = D-i-1;
            if(rem*9 >= S)
            {
                if(i==0)
                {
                    s+="1";
                    S-=1;
                }
                else 
                {
                    s+="0";
                }
            }
            else
            {
                int p = S-rem*9;
                if(p>9)return "-1";
                s+=to_string(p);
                S-=p;
            }
            
        }
        
        return s;
    }
};