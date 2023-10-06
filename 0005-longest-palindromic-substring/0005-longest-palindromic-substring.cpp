class Solution {
public:
    string longestPalindrome(string s) {
          int n = s.length();
        vector<vector<int>> dp(n,vector<int>(n,0));
        int start = 0,end = 0 ;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                if(g == 0){
                    dp[i][j] = 1;
                }
                else if(g == 1){
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                    }
                }
                else{
                    if(s[i]==s[j] && dp[i+1][j-1]==1){
                        dp[i][j] = 1;
                    }
                }
               if(dp[i][j]==1){
                   start = i;
                   end = j;
               }
            }
        }
        return s.substr(start,end-start+1);
    }
};