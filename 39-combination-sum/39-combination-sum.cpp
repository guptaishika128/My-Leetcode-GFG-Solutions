class Solution {
public:
    void combination(int index, int target ,vector<int>& candidates, vector<vector<int>>& result, vector<int>& ds){
        
        if(index==candidates.size()){
            if(target == 0){
                result.push_back(ds);
            }
            return;
        }
    
        
        
        // When you decide to pick that element
        if(candidates[index]<=target){
            ds.push_back(candidates[index]);
            combination(index,target-candidates[index],candidates,result,ds);
            ds.pop_back();
        }
        
        // When we don't pick that element
        combination(index+1,target,candidates,result,ds);
}
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ds;
        combination(0,target,candidates,result,ds);
        return result;
    }
};