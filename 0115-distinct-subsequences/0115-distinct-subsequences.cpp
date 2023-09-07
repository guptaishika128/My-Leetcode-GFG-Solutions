class Solution {
public:
    int solve(int i, int j, string& s , string& t, vector<vector<double>>& dp){
        
        if(j<0){
            return 1;
        }
        if(i<0){
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        if(s[i] == t[j]){
            return dp[i][j] = solve(i-1,j-1,s,t,dp) + solve(i-1,j,s,t,dp);
        }
        return dp[i][j] = solve(i-1,j,s,t,dp);
    }
    int numDistinct(string s, string t) {
        static int MOD = (int)1e9 + 7; 
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
        
        for(int i=0;i<=s.length();i++){
            dp[i][0] = 1;
        }
        
        for(int i=1;i<=s.length();i++){
            for(int j=1;j<=t.length();j++){
                 if(s[i-1] == t[j-1]){
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j])%MOD;
                    }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][m];
    }
};