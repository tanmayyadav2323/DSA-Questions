

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>vec,sv(26,0),pv(26,0);
        if(s.size()<p.size())return vec;
        for(int i = 0; i<p.size(); i++)
        {
            sv[s[i]-'a']++;
            pv[p[i]-'a']++;
        }


        for(int i = p.size()-1; i<s.size() ; i++)
        {
            int index = i-p.size()+1;
            if(i>=p.size())sv[s[i]-'a']++;
            if(sv == pv)vec.push_back(index);
            sv[s[index]-'a']--;
        }

        return vec;
    }
};