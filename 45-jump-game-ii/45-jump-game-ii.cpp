class Solution {
public:
    int jump(vector<int>& nums) {
        int left =0;
        int right = 0;
        int jumps = 0;
        while(right<nums.size()-1){
            int maxreach = 0;
            for(int i=left;i<=right;i++){
                maxreach = max(maxreach,nums[i]+i);
            }
            left = right +1;
            right = maxreach;
            jumps+=1;
        }
        return jumps;
    }

};