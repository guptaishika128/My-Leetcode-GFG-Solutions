class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int min_diff = INT_MAX;
        int result = 0;
        for(int i=0;i<nums.size()-2;i++){
            int j = i+1;
            int k = nums.size()-1;
            while(j<k){  
            int sum = nums[i] + nums[j] + nums[k];
            if(abs(target-sum) < min_diff){
                min_diff = abs(target-sum);
                result = sum;
            } else if(sum>target){
                k--;
            } else{
                j++;
            }
            }
        }
        return result;
    }
};