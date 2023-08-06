class Solution {
public:
     long long MOD = 1000000007;
    int f(int i,int j,int n ,vector<vector<int>> &matrix,vector<vector<int>> &dp){
        
       if(j<0 || j>n-1){
            return INT_MAX;
        }
    
        if(i==0){ // we are on the first row
            return matrix[i][j];
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int d = matrix[i][j] + f(i-1,j,n,matrix,dp)%MOD;
        int ld = matrix[i][j] + f(i-1,j-1,n,matrix,dp)%MOD;
        int rd = matrix[i][j] + f(i-1,j+1,n,matrix,dp)%MOD;
        
        return dp[i][j] = min(min(d,ld),rd);
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
    
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }
        
     for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int ld=1e9,rd=1e9;
                
                
                int up=matrix[i][j] + dp[i-1][j];
                
                if(j-1>=0)
                    ld=matrix[i][j] + dp[i-1][j-1];
                if(j+1<m)
                    rd=matrix[i][j] + dp[i-1][j+1];
                
                dp[i][j] = min(up,min(ld,rd));
                
                
                
            }
        }
        
        int mini= INT_MAX;
        
        for(int j=0;j<n;j++){
            mini = min(mini ,dp[n-1][j]);
        }
        return mini;
    }
};