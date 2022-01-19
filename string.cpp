
class Solution {
    vector<vector<string>>vc;
    vector<vector<int>>vec;
    string s;
public:

   void expand(int low ,int high,vector<vector<int>>&v)
   {
      while(low>=0 && high<s.length() && s[low] == s[high])v.push_back({low--,high++});
   }

    void search(int index,vector<string>v)
    {
      if(index >= s.length())vc.push_back(v);
      else 
      {
        for(int i = 0; i<vec.size() ; i++)
        {
          if(vec[i][0] == index)
          {
            v.push_back(s.substr(vec[i][0],vec[i].size()==1?1:vec[i][1]-vec[i][0]+1));
            search(vec[i][vec[i].size()==1?0:1]+1,v);
            v.pop_back();
          }
        }
      }
    }

    vector<vector<string>> partition(string t)
    {
      s=t;
      for(int i = 0 ; i<s.length()  ; i++)
      {
        vec.push_back({i});
        if(i>0 && s[i] == s[i-1])expand(i-1,i,vec);
        if(i>1 && s[i] == s[i-2])expand(i-2,i,vec);
      }
      search(0,{});
      return vc;
    }
};