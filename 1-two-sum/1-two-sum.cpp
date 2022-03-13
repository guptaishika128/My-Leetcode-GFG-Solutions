class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       vector<int> ans;
        unordered_map<int,int> map;
        
        for(int i=0;i<nums.size();i++){
            if(map.find(target-nums[i]) == map.end()){
                map[nums[i]] = i;
            } else {
                ans.push_back(map[target-nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};