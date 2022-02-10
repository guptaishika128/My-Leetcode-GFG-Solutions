class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int lfnz = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] != 0){
            nums[lfnz++] = nums[i];
            }
        }
        
        for(int i=lfnz;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};