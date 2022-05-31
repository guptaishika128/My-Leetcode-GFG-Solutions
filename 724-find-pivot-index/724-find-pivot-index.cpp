class Solution {
public:
    int pivotIndex(vector<int>& nums) {
         int total = 0;
        int prefixS = 0;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
        }
        
        for(int i=0;i<nums.size();prefixS+=nums[i++]){
            if(prefixS*2 == total-nums[i]){
                return i;
            }
        }
        return -1;
    }
};