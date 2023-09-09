class Solution {
public:
    int solve(int idx, int t, vector<int>& satisfaction,vector<vector<int>>& dp){
        int n = satisfaction.size();
        if(idx == n){
            return 0;
        }
        
        if(dp[idx][t] != -1){
            return dp[idx][t];
        }
        
        int notTake = solve(idx+1,t,satisfaction,dp);
        int take = satisfaction[idx]*t + solve(idx+1,t+1,satisfaction,dp);
        return dp[idx][t] = max(notTake,take);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
         int n = satisfaction.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return solve(0,1,satisfaction,dp);
    }
};