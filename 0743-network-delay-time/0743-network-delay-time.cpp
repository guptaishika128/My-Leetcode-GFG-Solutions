class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k)      {
        
        vector<pair<int,int>> adj[n+1];
        
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];
            adj[u].push_back({v,wt});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,k}); // {dist,source}
        
        vector<int> dist(n+1,1e9);
        dist[k] = 0;
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int v = it.first;
                int w = it.second;
                if(dis + w < dist[v]){
                    dist[v] = dis+w;
                    pq.push({dist[v],v});
                }
            }
        }
        int maxi = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 1e9){
                return -1;
            }
            else{
                maxi = max(maxi,dist[i]);
            }
        }
        return maxi;
    }
};