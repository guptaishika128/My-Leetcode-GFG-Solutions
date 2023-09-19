class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        if(grid[0][0] == 1){
            return -1;
        } else{
        dist[0][0] = 1;
        q.push({1,{0,0}}); // pushing src dist and index in queue
        }
        if(n == 1){
            return 1?grid[0][0]==0:grid[0][0]==1;
        }
        vector<int> dr = {-1,-1,-1,0,0,1,1,1};
        vector<int> dc = {-1,0,1,-1,1,-1,0,1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            for(int i=0;i<8;i++){
                int nr = r+dr[i];
                int nc = c+dc[i];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && 
                   grid[nr][nc] == 0 && dis + 1 <dist[nr][nc]){                         dist[nr][nc] = 1 + dis;
                    if(nr == n-1 && nc == n-1){
                        return dis+1;
                    }
                      q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
            
        return -1;
    }
};