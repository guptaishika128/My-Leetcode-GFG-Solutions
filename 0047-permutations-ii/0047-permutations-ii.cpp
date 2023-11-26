class Solution {
public:
    vector<vector<int>> result;
    set<vector<int>> st;
    void solve(int idx,int n , vector<int>& nums){
        
        if(idx == n){
            if(st.find(nums)==st.end()){
                st.insert(nums);
                result.push_back(nums);
            }
        }
        for(int j=idx;j<n;j++){
            swap(nums[j],nums[idx]);
            solve(idx+1,n,nums);
            swap(nums[j],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        solve(0,nums.size(),nums);
        return result;
    }
};