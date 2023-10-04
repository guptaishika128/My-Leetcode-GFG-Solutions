class Solution {
public:
    
    int solve(int idx, vector<int>& arr, int k,vector<int>& dp){
        int n = arr.size();
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        int len = 0;
        int maxi = INT_MIN;
        int maxans = INT_MIN;
        
        for(int j=idx;j<min(n,idx+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = len*maxi + solve(j+1,arr,k,dp);
            maxans = max(maxans,sum);
        }
        
        return dp[idx] = maxans;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        return solve(0,arr,k,dp);
    }
};