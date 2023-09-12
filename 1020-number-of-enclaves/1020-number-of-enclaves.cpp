class Solution {
public:
    
     void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<int>& delRow, vector<int>& delCol){
        int m = grid.size();
        int n = grid[0].size();
        
        vis[i][j] = 1;
        
        for(int k=0;k<4;k++){
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc] == 1){
                dfs(nr,nc,vis,grid,delRow,delCol);
            }
        }
        
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        for(int i=0;i<m;i++){
            if(!vis[i][0] && grid[i][0] == 1){
                dfs(i,0,vis,grid,delRow,delCol);
            }
            if(!vis[i][n-1] && grid[i][n-1] == 1){
                dfs(i,n-1,vis,grid,delRow,delCol);
            }
        }
        
        for(int j=0;j<n;j++){
            if(!vis[0][j] && grid[0][j] == 1){
                dfs(0,j,vis,grid,delRow,delCol);
            }
            if(!vis[m-1][j] && grid[m-1][j] == 1){
                dfs(m-1,j,vis,grid,delRow,delCol);
            }
        }
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};