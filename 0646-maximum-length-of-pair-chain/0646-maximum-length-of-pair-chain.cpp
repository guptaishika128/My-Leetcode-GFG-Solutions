class Solution {
public:
    int solve(int ind,int prev,int n, vector<vector<int>>& pairs,vector<vector<int>>& dp){
       if(ind == n){
           return 0;
       }
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        
        int notTake = solve(ind+1,prev,n,pairs,dp);
        
        int take = INT_MIN;
        
        if(prev == -1 || pairs[prev][1]<pairs[ind][0]){
            take = 1 + solve(ind+1,ind,n,pairs,dp);
        }
        
        return dp[ind][prev+1] = max(take,notTake);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        vector<vector<int>>dp (n,vector<int>(n+1,-1));
        sort(pairs.begin(),pairs.end());
        return solve(0,-1,n ,pairs,dp);
        
    }
};