class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int wt = flights[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int> dist(n,1e9);
        dist[src] = 0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}}); // {stops,{node,dist}}
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            
            if(stops>k){
                continue;
            }
            
            for(auto itr:adj[node]){
                int adjNode = itr.first;
                int wt = itr.second;
                
                if(cost + wt < dist[adjNode] && stops<=k){
                    dist[adjNode] = cost+wt;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst] == 1e9){
            return -1;
        }
        return dist[dst];
    }
};