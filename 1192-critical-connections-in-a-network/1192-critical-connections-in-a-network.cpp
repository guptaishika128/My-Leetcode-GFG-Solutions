class Solution {
private: int timer = 1;
    
public:
    void dfs(int node, int parent, vector<int> adj[], vector<int>& visited, vector<int>& low, vector<int>& tin, vector<vector<int>>& bridges){
        visited[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        
        for(auto it:adj[node]){
            if(it == parent){
                continue;
            }
            if(!visited[it]){
                dfs(it,node,adj,visited,low,tin,bridges);
                low[node] = min(low[it],low[node]); // node is greedy he will ask it wait you have come back what's your lowest time
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else{
                low[node] = min(low[it],low[node]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        // Implementation of Trajan's Algo
        vector<vector<int>> bridges;
        vector<int> adj[n];
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> visited(n,0);
        vector<int> low(n,0);
        vector<int> tin(n,0);
        dfs(0,-1,adj,visited,low,tin,bridges);
        return bridges;
    }
};