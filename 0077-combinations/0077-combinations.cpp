class Solution {
public:
    
    void dfs(int idx, int k, int n ,vector<int> temp, vector<vector<int>>& result){ 
        if(temp.size() == k){
            result.push_back(temp);
            return;
        } 
        else {
            for(int j=idx;j<=n;j++){
                temp.push_back(j);
                dfs(j+1,k,n,temp,result);
                temp.pop_back();
            }
        }
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        dfs(1,k,n,temp,result);
        return result;
    }
};