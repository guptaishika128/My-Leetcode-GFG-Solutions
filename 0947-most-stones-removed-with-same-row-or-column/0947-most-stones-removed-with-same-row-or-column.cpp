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
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int maxRow = 0;
        int maxCol = 0;
        
        for(auto it:stones){
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }
        
        DisjointSet ds(maxRow+maxCol+1);
        
        for(auto it:stones){
            int nodeRow = it[0];
            int nodeCol = maxRow+it[1]+1;
            ds.unionBySize(nodeRow,nodeCol);
        }
        int cnt = 0;
        for(int i=0; i<=maxRow+maxCol+1;  ++i)
            if(ds.parent[i] == i and ds.size[i] > 1)cnt++;
        
        return n-cnt;
    }
};