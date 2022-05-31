class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //  Using Boyer-Moore Voting Algorithm
        int count = 0;
        int elem = 0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                elem = nums[i];
            }
            count += (elem == nums[i]) ? 1 : -1;
        }
    return elem;
    }
};