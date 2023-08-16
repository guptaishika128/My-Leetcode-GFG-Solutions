class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        if(nums.size()<=1){
            return nums.size();
        }
        
        int currentStreak = 1;
        int maxi = 0;
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1]){
                if(nums[i] == (nums[i-1] + 1)){
                    currentStreak++; 
                } 
                else{
                     maxi = max(maxi , currentStreak);
                    currentStreak = 1;
                }
            } 
        }
        return max(maxi,currentStreak);
    }
};