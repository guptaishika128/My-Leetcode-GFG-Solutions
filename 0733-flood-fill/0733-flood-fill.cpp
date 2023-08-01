class Solution {
public:
    void dfs(int r, int c , vector<vector<int>>& ans,vector<vector<int>>& image, int color, vector<int>& delRow , vector<int>& delCol, int iniColour){
        int m = image.size();
        int n = image[0].size();
    
        
        ans[r][c] = color;
        
        for(int i=0;i<4;i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow>=0  && nrow<m && ncol >=0 && ncol<n && image[nrow][ncol] == iniColour && ans[nrow][ncol] != color){
                dfs(nrow,ncol,ans,image,color,delRow,delCol,iniColour);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        
        vector<vector<int>> ans = image;
        vector<int> delRow = {-1,0,+1,0};
        vector<int> delCol = {0,+1,0,-1};
        dfs(sr, sc, ans , image, color, delRow, delCol, initialColor);
        return ans;
    }
};