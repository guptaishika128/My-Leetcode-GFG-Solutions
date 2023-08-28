class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 1;
        }
        vector<int> dp(n);
        // dp[i] -> stores length of lis that ends that nums[i]
        dp[0] = 1; //  Base case
        int ans = 0;
        for(int i=1;i<n;i++){
            int curr_max = 0;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(curr_max<dp[j]){
                        curr_max = dp[j];
                    }
                }
            }
            dp[i] = curr_max + 1;
            
            if(ans<dp[i]){
                ans = dp[i];
            }
        }
        return ans;
    }
};