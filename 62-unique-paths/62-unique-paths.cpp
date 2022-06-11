class Solution {
public:
 /*   int pathsCount(int m , int n,  vector<vector<int>>& dp){
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        int up = pathsCount(m-1,n,dp);
        int left = pathsCount(m,n-1,dp);
        
        return dp[m][n] = up+left;
    }
    */
    int uniquePaths(int m, int n) {
       /* vector<vector<int>> dp(m,vector<int>(n,-1));
        return pathsCount(m-1,n-1,dp);
      */
        int totaldir = m+n-2;
        int r = m-1;
        double res = 1;
        
        for(int i=1;i<=r;i++){
            res = res*(totaldir-r+i)/i;
        }
        return (int)res;
    }
};