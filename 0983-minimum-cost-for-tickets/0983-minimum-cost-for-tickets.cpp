class Solution {
public:
    int solve(int i , int validity , vector<int>& days, vector<int>& costs, vector<vector<int>>& dp){
        
        if(i>=days.size()){
            return 0;
        }
        
        if(dp[i][validity]!=-1){
            return dp[i][validity];
        }
        
        
        if(days[i]<=validity){
            return dp[i][validity] = solve(i+1,validity,days,costs,dp);
        }
        else{
            int cost1 = costs[0] + solve(i+1,days[i]+0,days,costs,dp);
            int cost2 = costs[1] + solve(i+1,days[i]+6,days,costs,dp);
            int cost3 = costs[2] + solve(i+1,days[i]+29,days,costs,dp);
            return dp[i][validity] = min(cost1,min(cost2,cost3));
        }
    }
    
    
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        int max_validity = days[n-1]+30;
        vector<vector<int>> dp(n,vector<int>(max_validity,-1));
        return solve(0,0,days,costs,dp);
    }
};