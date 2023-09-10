class Solution {
public:
    
    int solve(int idx, int k, vector<int>& arr, vector<int>& dp){
        int n =arr.size();
        
        if(idx == n){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int len = 0;
        int ans = 0;
        int maxi = 0;
        for(int i = idx;i<min(n,idx+k);i++){
            len++;
            maxi = max(maxi,arr[i]);
            ans = max(ans,len*maxi + solve(i+1,k,arr,dp));
        }
        return dp[idx] = ans;
    }
    
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,k,arr,dp);
    }
};