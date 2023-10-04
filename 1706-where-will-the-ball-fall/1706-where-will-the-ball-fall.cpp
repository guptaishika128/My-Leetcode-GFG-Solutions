class Solution {
public:

vector<int> findBall(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();

    std::vector<int> result(m);

    for (int b = 0; b < m; b++) {
        int currRow = 0, currCol = b;

        while (currRow < n) {
            if (grid[currRow][currCol] == 1 && currCol + 1 < m && grid[currRow][currCol + 1] == 1) {
                currRow++;
                currCol++;
            } else if (grid[currRow][currCol] == -1 && currCol - 1 >= 0 && grid[currRow][currCol - 1] == -1) {
                currRow++;
                currCol--;
            } else {
                break;
            }
        }
        result[b] = (currRow == n) ? currCol : -1;
    }
    return result;
}

};