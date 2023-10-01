class Solution {
public:
    
    void dfs(int node,vector<vector<int>>& graph, vector<int> temp, vector<vector<int>>& result){
        temp.push_back(node);
        if(node == graph.size()-1){
            result.push_back(temp);
        } else{
                for(auto it:graph[node]){
                 dfs(it,graph,temp,result);
                }
            }
        // temp.pop_back();
    }

    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> temp;
        dfs(0,graph,temp,result);
        return result;
    }
};