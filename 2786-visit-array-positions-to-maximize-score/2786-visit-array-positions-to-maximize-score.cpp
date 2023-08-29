class Solution {
public:
    long long solve(int idx, int prev , int x , vector<int>& nums , vector<vector<long long>>& dp){
        if(idx == nums.size()){
            return 0;
        }
        
        long long pick = -1e12;
        if(dp[idx][prev]!=-1){
            return dp[idx][prev];
        }
        
        if(nums[idx] % 2 == prev){
            pick = nums[idx] + solve(idx+1,prev,x,nums,dp);
        }
        else{
            pick = nums[idx] - x + solve(idx+1,nums[idx]%2,x,nums,dp);
        }
        long long notPick = 0 + solve(idx+1,prev,x,nums,dp);
        
        return dp[idx][prev] = max(pick,notPick);
    }
    
    
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size()+1, vector<long long>(2,-1));
        return solve(0,nums[0]%2,x,nums,dp);
    }
};