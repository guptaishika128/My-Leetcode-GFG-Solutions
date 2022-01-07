
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int flag =0;
        for(int i=0;i<=n-2;i++){
            if(nums[i]==nums[i+1]){
                flag =1;
                return true;
                break;
            }
        }
    return false;
    }
};