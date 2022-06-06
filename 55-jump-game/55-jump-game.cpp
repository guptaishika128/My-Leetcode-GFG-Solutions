class Solution {
public:
    bool canJump(vector<int>& nums) {
       int p = nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(i > p)
                return false;
            p = max(i + nums[i], p);
        }
        return true;
    }
};