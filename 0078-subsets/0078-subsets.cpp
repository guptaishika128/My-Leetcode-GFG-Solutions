class Solution {
public:
    void printSubsets(vector<int>& nums, int index , vector<int>& ds,vector<vector<int>>& result,set<vector<int>>& s){
        if(index>=nums.size()){
  
            if(s.find(ds)==s.end()){
            s.insert(ds);
            result.push_back(ds);
            }
            return;
        }
        
        ds.push_back(nums[index]);
        printSubsets(nums,index+1,ds,result,s);
        ds.pop_back();
        
        printSubsets(nums,index+1,ds,result,s);
      
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> ds;
        set<vector<int>> s;
        printSubsets(nums,0,ds,result,s);
        return result;
    }
};