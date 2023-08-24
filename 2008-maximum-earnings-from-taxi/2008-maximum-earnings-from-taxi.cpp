class Solution {
public:
     long long solve(int idx, vector<vector<int>>& rides, vector<long long>& dp){
        
        if(idx >= rides.size()){
            return 0;
        }
        
        if(dp[idx] != -1){
            return dp[idx];
        }
        
        long long notTake = solve(idx+1,rides,dp);
        
        int low = idx+1;
        int high = rides.size()-1;
        int next_idx = -1;
        
        // finding the idx for the next offer if we take idx as the current offer
        while(low<=high){
            int mid = low +(high-low)/2;
            
            if(rides[mid][0]>=rides[idx][1]){ //  start value should be greater than the last end value
                next_idx = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        long long take = (rides[idx][1]-rides[idx][0]+rides[idx][2]) + solve(next_idx, rides, dp);
        return dp[idx] = (long long)max(take, notTake);
    }
    
    
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        int m = rides.size();
        
        sort(rides.begin(),rides.end());
        
        vector<long long> dp(m,-1);
        return solve(0,rides,dp);
    }
};