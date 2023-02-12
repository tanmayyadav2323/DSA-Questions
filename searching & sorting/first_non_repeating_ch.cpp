	public:
		string FirstNonRepeating(string A){
		    queue<char>q;
		    vector<int>v(26,0);
		    
		    for(int i  = 0; i<A.size() ; i++)
		    {
		        if(v[A[i]-'a'] == 0)
		        {
		            q.push(A[i]);v[A[i]-'a']=1;
		        }
		        else v[A[i]-'a']=-1;
		        
		        while(q.empty() == false && v[q.front()-'a']==-1)q.pop();
		        
		        if(q.empty())A[i]='#';
		        else A[i]=q.front();
		    }
		    
		    return A;
		}

};