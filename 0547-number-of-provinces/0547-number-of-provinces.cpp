class Solution {
private: 
    
    void dfs(int node,vector<bool>& visited,vector<int> adj[]){
        
        visited[node] = 1;
        for(auto it:adj[node]){
           if(!visited[it])
                dfs(it,visited,adj);
        }
    }

    
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];
        
       vector<bool> visited(n, false);
        
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                cnt++;
                dfs(i,visited,adj);
            }
        }
        return cnt;
    }
};