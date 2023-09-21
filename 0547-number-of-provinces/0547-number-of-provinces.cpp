class DisjointSet{
 
public:
    vector<int> parent,rank,size;
    
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionByRank(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u]>rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        } else if(rank[ulp_u]<rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        } else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};

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
        
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1){
                    ds.unionByRank(i,j);
                }
            }
        }
        
        int cnt = 0;
        
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                cnt++;
            }
        } 
        return cnt;
        
        
        
        
//         vector<int> adj[n];
        
//        vector<bool> visited(n, false);
        
//         int cnt = 0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<n;j++){
//                 if(isConnected[i][j] == 1 && i!=j){
//                     adj[i].push_back(j);
//                     adj[j].push_back(i);
//                 }
//             }
//         }
        
//         for(int i=0;i<n;i++){
//             if(!visited[i]){
//                 cnt++;
//                 dfs(i,visited,adj);
//             }
//         }
//         return cnt;
    }
};