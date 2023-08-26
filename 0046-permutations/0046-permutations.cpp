class Solution {
public:
    void solve(int ind, int n ,vector<int>& nums, vector<vector<int>>& result){
        if(ind == n){
            result.push_back(nums);
        }
        else{
            for(int j=ind;j<n;j++){
                swap(nums[ind],nums[j]);
                solve(ind+1,n,nums,result);
                swap(nums[ind],nums[j]);
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        solve(0,nums.size(),nums,result);
        return result;
    }
};