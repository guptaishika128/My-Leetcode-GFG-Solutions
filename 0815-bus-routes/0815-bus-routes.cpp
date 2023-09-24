class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        // least number of buses
        int n  = routes.size();
        vector<int> adj[1000010];
        
        for(int i=0; i<routes.size(); i++){
            int busNo = i;

            for(int j=0; j<routes[i].size(); j++){
                int route = routes[i][j];
                adj[route].push_back(busNo);
        }
    }
        
        queue<pair<int,int>> q;
        q.push({source,0}); // {src,stops}
        unordered_set<int> seen;
        seen.insert(source);
       
        
        while(!q.empty()){
            auto k = q.front();
            int station = k.first;
            int buses = k.second;
            q.pop();
            
            if(station == target){
                return buses;
            }
            for (int i : adj[station]) {
                for (int j : routes[i]) {
                    if (seen.find(j) == seen.end()) {
                        seen.insert(j);
                        q.push({j, buses + 1});
                    }
                }
                routes[i].clear();
            }
           
        }
        
        return -1;
        
    }
};