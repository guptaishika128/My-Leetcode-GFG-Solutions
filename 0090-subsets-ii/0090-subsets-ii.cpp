class Solution {
public:
     void printSubsets(vector<int>& nums, int index , vector<int>& ds,vector<vector<int>>& result){
       result.push_back(ds);
        
         for(int i=index;i<nums.size();i++){
             if(i!=index && nums[i] == nums[i-1]){
                 continue;
             }
            ds.push_back(nums[i]);
            printSubsets(nums,i+1,ds,result);
            ds.pop_back();
         }
      
      
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         vector<vector<int>> result;
        sort(nums.begin(),nums.end());
        vector<int> ds;
        printSubsets(nums,0,ds,result);
        return result;
    }
};