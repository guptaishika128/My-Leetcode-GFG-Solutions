class Solution {
public:
    int solve(int ind, int amt, vector<int>& coins, vector<vector<int>>& dp){
        
        if(ind == 0){
            if(amt%coins[ind] == 0){
                return amt/coins[ind];
            }else{
                return 1e9;
            }
        }
        if(dp[ind][amt] != -1){
            return dp[ind][amt];
        }
        
        int notTake = 0 + solve(ind-1,amt,coins,dp);
        
        int take = 1e9;
        
        if(coins[ind]<=amt){
            take = 1 + solve(ind,amt-coins[ind],coins,dp);
        }
        
        return dp[ind][amt] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = solve(n-1,amount,coins,dp);
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};