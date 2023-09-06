class Solution {
public:
    int lcs(string s, string t){
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                char c1 = s[i-1];
                char c2 = t[j-1];
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
    
    int pcs(string s){
        string t = s;
        reverse(t.begin(),t.end());
        return lcs(s,t);
    }
    int minInsertions(string s) {
        int n = s.length();
        return n - pcs(s);
    }
};