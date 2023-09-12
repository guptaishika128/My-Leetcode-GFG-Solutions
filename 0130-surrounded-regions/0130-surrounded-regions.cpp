class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<char>>& board, vector<int>& delRow, vector<int>& delCol){
        int m = board.size();
        int n = board[0].size();
        
        vis[i][j] = 1;
        
        for(int k=0;k<4;k++){
            int nr = i + delRow[k];
            int nc = j + delCol[k];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc] == 'O'){
                dfs(nr,nc,vis,board,delRow,delCol);
            }
        }
        
    }
    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i,0,vis,board,delRow,delCol);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i,n-1,vis,board,delRow,delCol);
            }
        }
        
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0,j,vis,board,delRow,delCol);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1,j,vis,board,delRow,delCol);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
               if(vis[i][j] == 0){
                   board[i][j] = 'X';
               } 
            }
        }
    }
};