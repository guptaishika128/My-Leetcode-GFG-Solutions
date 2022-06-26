class Solution {
public:
     void dfs(int i, int j ,vector<vector<char>>& grid){
         // boundary checking
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size())
            return;
        // return if current position is of water or is already visited
        if(grid[i][j] == '2' || grid[i][j] == '0')
            return;
        
        // mark the current as visited
        grid[i][j] = '2';
        
        // do DFS in all 4 directions
        dfs(i+1, j , grid);
        dfs(i, j-1 , grid);
        dfs(i-1, j , grid);
        dfs(i, j+1 , grid);
         
    }
    int numIslands(vector<vector<char>>& grid) {
         int islands = 0;
        // We make each 1 as 2 in when it is visited
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                // do DFS in case has not been visited and there is land
                if(grid[i][j] == '1') {
                    dfs(i,j,grid);
                    ++islands;
                } 
            }
        }
        return islands;     
    }
};