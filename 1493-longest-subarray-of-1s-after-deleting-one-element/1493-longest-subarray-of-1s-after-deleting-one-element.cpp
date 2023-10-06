class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zeroCnt = 0;
        int start = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            zeroCnt += (nums[i]==0);
            
            while(zeroCnt>1){
                zeroCnt -= (nums[start]==0);
                start++;
            }
            
            maxi = max(maxi,i-start);
        }
        return maxi;
    }
};