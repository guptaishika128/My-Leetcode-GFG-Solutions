class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
cin.tie(nullptr);
cout.tie(nullptr);
        
        
        int curr_max = 0;
        int max_sum = INT_MIN;
        int curr_min = 0;
        int min_sum = INT_MAX;
        int totalSum = 0;
        
        for(int i=0;i<nums.size();i++){
            curr_max = max(curr_max + nums[i] , nums[i]);
            max_sum = max(curr_max , max_sum);
            
            curr_min = min(curr_min + nums[i] , nums[i]);
            min_sum = min(curr_min , min_sum);
            
            totalSum+=nums[i];
        }
        return max_sum > 0 ? max(max_sum , totalSum - min_sum) : max_sum;
    }
};