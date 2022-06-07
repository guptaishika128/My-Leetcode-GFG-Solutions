class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> res;
        for(int i=1;i<=nums.size()-1;i++){
            if(nums[i] == nums[i-1]){
                res.push_back(nums[i]);
                i++;
            }
        }
        return res;
    }
};