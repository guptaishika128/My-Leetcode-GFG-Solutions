class Solution {
public:
    
    
    void solve(vector<int>& nums, int idx, vector<int>& temp , set<vector<int>>& result){
        int n = nums.size();
        if(idx >= n){
            if(temp.size()>1)
                result.insert(temp);
            return;
        }
        if(temp.size() == 0 || nums[idx]>=temp.back()){
            temp.push_back(nums[idx]);
            solve(nums,idx+1,temp,result);
            temp.pop_back();
        }
        solve(nums,idx+1,temp,result);
    }
    
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> temp;
        set<vector<int>> result;
        solve(nums,0,temp,result);
        return vector(result.begin(),result.end());
    }
};