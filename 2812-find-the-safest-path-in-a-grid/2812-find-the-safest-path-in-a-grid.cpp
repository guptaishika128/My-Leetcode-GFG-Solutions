class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        // Step-1 To find the minimum safeness factor of every cell
        int n = grid.size();
        vector<vector<int>> distToThief(n,vector<int>(n,0));
        vector<vector<int>> visited(n,vector<int>(n,0));
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    q.push({0,{i,j}});
                    distToThief[i][j] = 0;
                    visited[i][j] = 1;
                }
            }
        }
        
        vector<int> dr = {0,1,0,-1};
        vector<int> dc = {1,0,-1,0};
        
        while(!q.empty()){
            auto i = q.front();
            q.pop();
            int dis = i.first;
            int row = i.second.first;
            int col = i.second.second;
            
            distToThief[row][col] = dis;
            for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                    q.push({dis+1,{nr,nc}});
                    visited[nr][nc] = 1;
                }
            }
        }
        
        int ans = INT_MAX;
        
        visited.assign(n,vector<int>(n,0));
        priority_queue<pair<int,pair<int,int>>> pq;
        pq.push({distToThief[0][0],{0,0}});
        visited[0][0] = 1;
        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();
            int dis = i.first;
            int row = i.second.first;
            int col = i.second.second;
            
            ans = min(ans,dis);
            if(row == n-1 && col == n-1){
                return ans;
            }
             for(int k=0;k<4;k++){
                int nr = row + dr[k];
                int nc = col + dc[k];
                
                if(nr>=0 && nr<n && nc>=0 && nc<n && !visited[nr][nc]){
                    pq.push({distToThief[nr][nc],{nr,nc}});
                    visited[nr][nc] = 1;
                }
            }
            
            
        }
        return ans;
    }
};