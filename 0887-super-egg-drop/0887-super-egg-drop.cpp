class Solution {
public:
    int solve(int eggs, int floors,vector<vector<int>>& dp){
        if(eggs == 1){
            return floors;
        }
        
       if(floors == 0) return 0;
        
        if(dp[eggs][floors]!=-1){
            return dp[eggs][floors];
        }
        int mini = INT_MAX;
        int l = 1;
        int r = floors;
        
        while(l<=r){
            int mid = (l+r)/2;
            
            int left = solve(eggs-1,mid-1,dp);
            int right = solve(eggs,floors-mid,dp);
            int temp = 1 + max(left,right);
            if(left<right){
                l = mid+1;
            }
            else{
                r = mid-1;
            }
            mini = min(mini, temp);
        }
        return dp[eggs][floors] = mini;
    }
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k+1,vector<int>(n+1,-1));
        return solve(k,n,dp);
    }
};