class Solution {
public:
    
    int solve(int idx, vector<int>& stoneValue , int n, vector<int>& dp){
        if(idx>=n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int result = stoneValue[idx] - solve(idx+1,stoneValue,n,dp);
        
        if(idx+1<n){
            result = max(result,stoneValue[idx] + stoneValue[idx+1] - solve(idx+2,stoneValue,n,dp));
        }
        
        if(idx+2<n){
            result = max(result,stoneValue[idx] + stoneValue[idx+1] + stoneValue[idx+2]- solve(idx+3,stoneValue,n,dp));
        }
        
        return dp[idx] = result;
    }
    
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        
        vector<int> dp(n+1,-1);
        int diff = solve(0,stoneValue,n,dp);
        
        if(diff>0){
            return "Alice";
        } else if(diff<0){
            return "Bob";
        }
        return "Tie";
        
    }
};