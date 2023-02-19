class Solution {
public:
    //check Valid Tree
    bool checkCycle(vector<int>adj[],int s,int parent,vector<bool>&visited)
    {
        visited[s]=true;
        for(int v: adj[s])
        {
            if(v != parent)
            {
                if(visited[v])return true;
                if(checkCycle(adj,v,s,visited))return true;
            }
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<bool> visited(n,false);
        
        for(int i = 0; i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        if(checkCycle(adj,0,-1,visited))return false;
        for(int v : visited)if(v == false)return false;
        return true;
    }
};