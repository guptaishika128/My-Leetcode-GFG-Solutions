class Solution {
public:
    int solve(int eggs, int floors,vector<vector<int>>& dp){
        if(eggs == 1){
            return floors;
        }
        
       if(floors == 0 || floors == 1) return floors;
        
        if(dp[eggs][floors]!=-1){
            return dp[eggs][floors];
        }
        int mini = INT_MAX;
        
        for(int i=1;i<=floors;i++){
            int val = 1 + max(solve(eggs-1,i-1,dp),solve(eggs,floors-i,dp));
            mini = min(mini,val);
        }
        return dp[eggs][floors] = mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>> dp(3,vector<int>(n+1,-1));
        return solve(2,n,dp);
    }
};