class Solution {
public:
    int solve(int idx, vector<vector<int>>& interval , vector<int>& dp){
        if(idx>=interval.size()){
            return 0;
        }
        
        if(dp[idx]!=-1){
            return dp[idx];
        }
        
        
        int notTake = solve(idx+1,interval,dp);
        
        int low = idx+1;
        int high = interval.size()-1;
        int new_idx = -1;
        
        while(low<=high){
            int mid = low +(high-low)/2;
            
            if(interval[mid][0]>=interval[idx][1]){
                new_idx = mid;
                high  = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        int take = interval[idx][2] + solve(new_idx, interval,dp);
        return dp[idx] = max(take,notTake);
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = profit.size();
        vector<vector<int>> interval(n,vector<int>(3));
        
        for(int i =0;i<n;i++){
            interval[i] = {startTime[i],endTime[i],profit[i]};
        }
        
        vector<int> dp(n,-1);
        sort(interval.begin(),interval.end());
        return solve(0,interval,dp);
        
    }
};