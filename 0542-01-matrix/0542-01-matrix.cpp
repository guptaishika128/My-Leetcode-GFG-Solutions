class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!visited[i][j] && mat[i][j] == 0){
                    visited[i][j] = 1;
                    q.push({{i,j},0});
                }
            }
        }
        
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dis = q.front().second;
            q.pop();
            
            ans[r][c] = dis;
            
            for(int i=0;i<4;i++){
                int nr = r + delRow[i];
                int nc = c + delCol[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && mat[nr][nc] == 1){
                    visited[nr][nc] = 1;
                    q.push({{nr,nc},dis+1});
                }
            }
            
        }
        
        return ans;
    }
};