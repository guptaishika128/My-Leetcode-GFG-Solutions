class Solution {
public:
        void combination(int index, int target ,vector<int>& candidates, vector<vector<int>>& result, vector<int>& ds){
            if(target==0){
                result.push_back(ds);
            }
        
            for(int i=index;i<candidates.size();i++){
                if(i>index && candidates[i] == candidates[i-1]){
                    continue;
                }
              
                if(candidates[i]<=target){
                    ds.push_back(candidates[i]);
                    combination(i+1,target-candidates[i],candidates,result,ds);
                    ds.pop_back();
                }
            }
       
}
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> result;
        vector<int> ds;
        combination(0,target,candidates,result,ds);
        return result;
    }
};