class Solution{
public:
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int count = 0;
	    int row = -1;
	    
	    for(int i  = 0; i<n ; i++)
	    {
	        int c = 0;
	        for(int j = 0; j<m ; j++)
	        {
	            if(arr[i][j] == 1)c++;
	        }
	        if(c > count)
	        {
	            row = i;
	            count = c;
	        }
	    }
	    
	    return row;
	}

};