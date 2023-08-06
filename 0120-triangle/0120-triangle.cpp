class Solution {
public:
    // Triangular grid -> Fixed S.P. and variable ending pt
     int f(int i , int j ,int n, vector<vector<int>>& triangle,vector<vector<int>> &dp){
        if(i==n-1){
            return triangle[i][j];
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
         
        int d = triangle[i][j] + f(i+1,j,n,triangle,dp);
         
        int rd = triangle[i][j] + f(i+1,j+1,n,triangle,dp);
         
         return dp[i][j] = min(d,rd);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
        
        int n= triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d = triangle[i][j] + dp[i+1][j];
                int rd = triangle[i][j] + dp[i+1][j+1];
                
                dp[i][j] = min(d,rd);
            }
        }
        return dp[0][0];
       
    }
    
};