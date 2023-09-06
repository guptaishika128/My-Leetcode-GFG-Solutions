class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
       for(int i=1;i<dp.size();i++){
           for(int j=1;j<dp[0].size();j++){
               char c1 = text1[i-1];
               char c2 = text2[j-1];
               
               if(c1 == c2){
                   dp[i][j] = 1 + dp[i-1][j-1];
               }
               else{
                   dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
               }
           }
       }
        return dp[n][m];
    }
};