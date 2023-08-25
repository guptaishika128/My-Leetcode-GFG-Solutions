class Solution {
public:
    // Question is same as count partitions with difference k
    int solve(int ind, int target, vector<int>& nums, vector<vector<int>>& dp){
       
        if(ind == 0){
            if((target == 0) && (nums[ind] == 0)){
                return 2; // either u include it or exclude it
            } 
            if(target == 0 || nums[ind] == target){
                return 1;
            }
            return 0;
        }
        
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        
        int notTake = solve(ind-1,target,nums,dp);
        
        int take = 0;
        
        if(nums[ind]<=target){
            take = solve(ind-1,target-nums[ind],nums,dp);
        }
        
        return dp[ind][target] = take+notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for(int i=0;i<n;i++){
            totalSum += nums[i];
        }
        
        if(totalSum-target<0 || (totalSum-target)%2){
            return 0;
        }
        int k = (totalSum-target)/2;
        vector<vector<int>> dp(n,vector<int>(k+1,0));
        // return solve(n-1,k,nums,dp);
        
        if(nums[0] == 0){
            dp[0][0] = 2;
        }
        else{
            dp[0][0] = 1;
        }
        
        if(nums[0]!= 0  && nums[0]<=k){
            dp[0][nums[0]] = 1;
        }
        
        for(int ind=1;ind<n;ind++){
            for(int target = 0;target<=k;target++){
                    int notTake = dp[ind-1][target];
        
                    int take = 0;

                    if(nums[ind]<=target){
                        take = dp[ind-1][target-nums[ind]];
                    }

            dp[ind][target] = take+notTake;
            }
        }
        return dp[n-1][k];
    }
};