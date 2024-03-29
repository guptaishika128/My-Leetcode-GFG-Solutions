class Solution {
public:
    int dfs(int i, int j1, int j2, vector<vector<int>>& grid ,vector<vector<vector<int>>>& dp){
        int rows = grid.size();
        int cols = grid[0].size(); 
        
        if(j1<0 || j2<0 || j1>=cols || j2>=cols){
            return -1e8;
        }
        
        if(i == rows-1){
            if(j1 == j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1] + grid[i][j2];
            }
        }
        
        if(dp[i][j1][j2]!=-1){
            return dp[i][j1][j2];
        }
        
        int maxi = -1e8;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                int value = 0;
                if(j1 == j2){
                    value = grid[i][j1];
                }
                else{
                    value = grid[i][j1] + grid[i][j2];
                }
                value += dfs(i+1,j1+dj1,j2+dj2,grid,dp);
                maxi = max(maxi,value);
            }
        }
        return dp[i][j1][j2] =  maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
       int cols= grid[0].size(); 
        vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
        return dfs(0,0,cols-1,grid,dp);
       
    }
};