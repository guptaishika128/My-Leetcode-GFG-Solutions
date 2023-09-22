class Solution {
public:
    void printSubsets(vector<int>& nums, int index , vector<int>& ds,vector<vector<int>>& result){
        if(index>=nums.size()){
            result.push_back(ds);
            return;
        }
        
        ds.push_back(nums[index]);
        printSubsets(nums,index+1,ds,result);
        ds.pop_back();
        
        printSubsets(nums,index+1,ds,result);
        /*
         if(index>=nums.size()){
        result.push_back(ds);
        return;
    }
    
    // If pick
    ds.push_back(nums[index]);
    printSubsets(nums,index+1,ds,result);
    ds.pop_back();
    
    //If not pick
    printSubsets(nums,index+1,ds,result);
    */
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        printSubsets(nums,0,ds,result);
        return result;
    }
};