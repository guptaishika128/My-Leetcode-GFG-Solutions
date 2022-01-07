
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0;i<=n-2;i++){
            if(nums[i]==nums[i+1]){
                return true;
                break;
            }
        }
    return false;
    }
};