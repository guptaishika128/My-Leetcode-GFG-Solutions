class Solution {
public:
    const int MOD = 1e9+7;
    int solve(int dice, int k , int target, int sum , vector<vector<int>>& dp){
       if(dice == 0){
            if(sum == target){
                return 1;            
            }
           else{
               return 0;
           }
       }
        
        if(dp[dice][sum]!=-1){
            return dp[dice][sum];
        }
        
        
        long long ways = 0;
        for(int i=1;i<=k;i++){
                ways += solve(dice-1,k,target,sum+i,dp);
        }
    return dp[dice][sum] = ways%MOD;
    }

    int numRollsToTarget(int n, int k, int target) {
         if(n == 1){
            if(k>=target){
                return 1;
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(1001,-1));
        return solve(n,k,target,0,dp);
    }
};