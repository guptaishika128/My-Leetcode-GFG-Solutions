class Solution {
public:
    int f(int i, int j , vector<vector<int>>& triangle , vector<vector<int>>& dp){
        int n = triangle.size();
       
        if(i==n-1){
            return triangle[n-1][j];
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int down = f(i+1 , j , triangle,dp) + triangle[i][j];
        
        int dg = f(i+1 , j+1 , triangle,dp) + triangle[i][j];
        return dp[i][j] = min(down,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return f(0,0,triangle ,dp);
    }
};