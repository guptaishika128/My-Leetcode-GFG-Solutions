class Solution {
public:
    
    int solve(int i, int d, vector<int>& arr, vector<int>& dp){
       int n = arr.size();
        int ans = 1;
        
        if(dp[i]!=-1){
            return dp[i];
        }
        
        for(int j=i+1;j<=min(n-1,i+d) && arr[j]<arr[i];j++){
            ans = max(ans,1+solve(j,d,arr,dp));
        }
        
        for(int j=i-1;j>=max(0,i-d) && arr[j]<arr[i];j--){
            ans = max(ans,1+solve(j,d,arr,dp));
        }
        return dp[i] = ans;
    }
    
    
    int maxJumps(vector<int>& arr, int d) {
        int  n = arr.size();
        int ans = -1;
        vector<int> dp(n+1,-1);
        for(int i=0;i<n;i++){
            ans = max(ans,solve(i,d,arr,dp));
        }
        return ans;
    }
};