class Solution {
public:
    
    long long solve(int node,int parent,vector<int>& values, vector<int> adj[]){
        if(adj[node].size()==1 && node!=0)
            return values[node];
        long long sum = 0;
        for(auto it : adj[node]){
            if(it==parent)
                continue;
            sum += solve(it,node,values,adj);
        }
        return min(sum,1LL*values[node]);
    }
    
  
    
    long long maximumScoreAfterOperations(vector<vector<int>>& edges, vector<int>& values) {
        int n = values.size();
        vector<int> adj[n];
        
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
          long long ans = 0;
        for(int i=0;i<n;i++)
            ans += values[i];
        long long x = solve(0,-1,values,adj);
        
        return ans-x;
    }
};