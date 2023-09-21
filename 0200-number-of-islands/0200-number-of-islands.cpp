
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
    bool isValid(int nr, int nc, int n, int m){
        return nr>=0 && nr<n && nc>=0 && nc<m;
    }
    
public:
     void dfs(int i, int j ,vector<vector<char>>& grid){
         if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0')
            return;
        grid[i][j] = '0';
        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        DisjointSet ds(n*m);
         vector<int> dr = {-1,0,+1,0};
        vector<int> dc = {0,-1,0,+1};
        
      
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0'){
                    continue;
                }
               
                
                for(int k=0;k<4;k++){
                    int nr = i + dr[k];
                    int nc = j + dc[k];
                    
                    if(isValid(nr,nc,n,m)&& grid[nr][nc] == '1'){
                            int adjNodeNo = nr*m + nc;
                            int nodeNo = i*m + j;
                            ds.unionByRank(nodeNo,adjNodeNo);
                        }
                    }
      
                }
            }
        unordered_set<int> st;
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == '0') { 
                    continue;
                }
                int nodeNo = i*m + j;
                st.insert(ds.findUPar(nodeNo));
            }
        }
        
        return st.size();
         
    }
};