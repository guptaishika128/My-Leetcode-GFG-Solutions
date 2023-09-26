class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> edgefreq;
        
        int max_freq = 0;
        
        for(int row = 0;row<wall.size();row++){
            int edge_pos = 0;
            for(int brickNo = 0 ; brickNo<wall[row].size()-1;brickNo++){
                int curr_brick_length = wall[row][brickNo];
                edge_pos = edge_pos + curr_brick_length;
                edgefreq[edge_pos]++;
                max_freq = max(max_freq,edgefreq[edge_pos]);
            }
        }
        return wall.size() - max_freq;
    }
};