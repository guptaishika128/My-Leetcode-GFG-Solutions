class Solution {
public:
    
    int solve(int i, int j, string& s1, string& s2,vector<vector<int>>& dp){
       if(i<0 || j<0){
           return 0;
       }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int ans = 0;
        if(s1[i] == s2[j]){
            ans = s1[i] + solve(i-1,j-1,s1,s2,dp);
        }
        else{
            ans = max(solve(i-1,j,s1,s2,dp),solve(i,j-1,s1,s2,dp));
        }
        return dp[i][j] = ans;
    }
    
    
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        int sum = 0;
        for(auto i:s1){
            sum += i;
        }
        for(auto i:s2){
            sum += i;
        }
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return sum -2*solve(n-1,m-1,s1,s2,dp);
    }
};