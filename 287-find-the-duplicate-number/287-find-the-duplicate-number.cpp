class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Floyd's Cycle Detection Algo
        int fast = nums[0];
        int slow = nums[0];
        
        while(1){
            slow = nums[slow]; // slow moves by 1 step
            fast = nums[nums[fast]]; // fast moves by 2 steps
                
            if(slow==fast){
                break;
            }
        }
        
        fast = nums[0];
        
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[fast];
        }
        return slow;
    }
};
        
        
        
        
        
        
        
        
