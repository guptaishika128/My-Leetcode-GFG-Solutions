class Solution {
public:
    int solve(int idx, int buy, vector<int>& prices , vector<vector<int>>& dp, int fee){
        
        if(idx >= prices.size()){
            return 0;
        }
        
        if(dp[idx][buy]!=-1){
            return dp[idx][buy];
        }
        
        int profit = 0;
        
        if(buy){
            profit = max((-prices[idx] + solve(idx+1,0,prices,dp,fee)),(0+solve(idx+1,1,prices,dp,fee)));
        }
        else{
            profit = max((prices[idx] -fee + solve(idx+1,1,prices,dp,fee)),(0 + solve(idx+1,0,prices,dp,fee)));
        }
        
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
         int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solve(0,1,prices,dp,fee);
       
    }
};