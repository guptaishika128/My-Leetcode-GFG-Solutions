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
        // int ans = solve(n-1,amount,coins,dp);
        
        for(int i=0;i<=amount;i++){
            if(i%coins[0] == 0){
                dp[0][i] = i/coins[0]; 
            }
            else{
                dp[0][i] = 1e9;
            }
        }
        
        for(int ind=1;ind<n;ind++){
            for(int amt=0;amt<=amount;amt++){
                int notTake = 0 + dp[ind-1][amt];
        
                int take = 1e9;

                if(coins[ind]<=amt){
                    take = 1 + dp[ind][amt-coins[ind]];
                }

            dp[ind][amt] = min(take,notTake);
            }
        }
        
        int ans = dp[n-1][amount];
        
        if(ans>=1e9){
            return -1;
        }
        return ans;
    }
};