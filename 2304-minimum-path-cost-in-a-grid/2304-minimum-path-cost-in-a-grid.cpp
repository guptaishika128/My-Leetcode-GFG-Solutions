class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>> visited(m,vector<int>(n,1e9));
        priority_queue<vector<int>,vector<vector<int>>,
        greater<vector<int>>> pq;
        
        for(int j=0;j<n;j++){
            pq.push({grid[0][j],0,j});
        }
        
        while(!pq.empty()){
            auto node = pq.top();
            pq.pop();
            int costTillHere = node[0];
            int r = node[1];
            int c = node[2];
            
            if(r == m-1){
                return costTillHere;
            }
            
            for(int dy=0;r+1<m && dy<n;dy++){
                int newCost = costTillHere + moveCost[grid[r][c]][dy] + grid[r+1][dy];
                if(newCost < visited[r+1][dy]){
                    visited[r+1][dy] = newCost;
                    pq.push({newCost, r+1,dy});
                }
            }
        }
        return -1;
    }
};