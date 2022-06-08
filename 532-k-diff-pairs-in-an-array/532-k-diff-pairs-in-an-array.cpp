class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i = 0;
        int j = 1;
        for(i,j;i<nums.size() && j<nums.size();){
            if(i==j || nums[j]-nums[i]<k){
                j++;
            }
            else{
            if(nums[j]-nums[i]==k){
                count++;
                j++;
                while(j<nums.size() && nums[j]==nums[j-1]) j++;
            }
            i++;
            while(i<j && nums[i]==nums[i-1]) i++;
            }
            }
        return count;
    }
};