class Solution {
public:
    int lcs(string s1, string s2){
        int n = s1.length();
        int m = s2.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                char c1 = s1[i-1];
                char c2 = s2[j-1];
                if(c1 == c2){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(s.begin(),s.end());
        return lcs(s,t);
    }
};