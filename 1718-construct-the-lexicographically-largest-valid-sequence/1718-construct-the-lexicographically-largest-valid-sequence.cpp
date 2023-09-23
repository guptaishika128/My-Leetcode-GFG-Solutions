class Solution {
public:
    bool dfs(int idx, vector<int>& ans, int n, vector<int>& visited){
        if(idx == 2*n-1){
            return true;
        }
        
        if(ans[idx]>0){
            return dfs(idx+1,ans,n,visited);
        }
        
        for(int i=n;i>=1;i--){
            if(visited[i]){
                continue;
            }
            
            if(i!=1 && (i+idx>=ans.size() || ans[idx+i])){
                continue;
            }
            
            visited[i] = 1; // mark visited
            ans[idx] = i; 
            if(i!=1){
                ans[idx+i] = i;
            }
            
            if(dfs(idx+1,ans,n,visited) == true){
                return true;
            }
            
            visited[i] = 0;
            ans[idx] = 0;
             if(i!=1){
                ans[idx+i] = 0;
            }
        }
       return false;
    }
 
    vector<int> constructDistancedSequence(int n) {
        vector<int> ans(2*n-1,0);
        vector<int> visited(n+1,0);
        dfs(0,ans,n,visited);
        return ans;
    }
};