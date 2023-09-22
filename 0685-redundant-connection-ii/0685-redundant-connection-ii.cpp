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
    
    bool unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v){
            return false;
        }
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        return true;
    }
    int getLargetComponentSize() {
            int maxSize = 0;
            for (int i = 0; i < parent.size(); i++) {
                if (parent[i] == i && size[i] > maxSize) {
                    maxSize = size[i];
                }
            }
            
            return maxSize;
        }

};

class Solution {
public:
    
    vector<int> detectCycle(int n ,vector<vector<int>>& edges, vector<int>& skipEdge ){
        vector<int> temp;
        DisjointSet ds(n);
        for(auto it:edges){
            if(it == skipEdge){
                continue;
            }
            if(!ds.unionBySize(it[0],it[1])){
                return it;
            }
        }
        return temp;
    }
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
         int n = edges.size();
            vector<int> ans;
        vector<int> indegree(n+1,0);
        int hasTwoIndegrees = -1;
        for(auto it:edges){
            indegree[it[1]]++;
            if(indegree[it[1]] == 2){
                hasTwoIndegrees = it[1];
                break;
            }
        }
        if(hasTwoIndegrees == -1){
            return detectCycle(n,edges,ans);
        }
        
        for(int i=n-1;i>=0;i--){
            if(edges[i][1] == hasTwoIndegrees){
                if(detectCycle(n,edges,edges[i]).empty()){
                    return edges[i];
                }
            }
        }
        return ans;
    
    }
};