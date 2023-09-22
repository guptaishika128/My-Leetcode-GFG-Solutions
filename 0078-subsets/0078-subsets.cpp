class Solution {
public:
    void printSubsets(vector<int>& nums, int index , vector<int>& ds,vector<vector<int>>& result){
       result.push_back(ds);
        
        for(int i = index;i<nums.size();i++)
        {
        ds.push_back(nums[i]);
        printSubsets(nums,i+1,ds,result);
        ds.pop_back();
        }
        // printSubsets(nums,index+1,ds,result);
      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        printSubsets(nums,0,ds,result);
        return result;
    }
};