class Solution {
public:
    int n;
    int solve(int idx, int person, int M, vector<int>& piles ,int n,vector<vector<vector<int>>> &dp){
        if(idx >= n){
            return 0;
        }
        
        if(dp[idx][person][M] != -1){
            return dp[idx][person][M];
        }
        
        int result = (person == 1) ? -1 : INT_MAX;
        
        int stones = 0;
        
        for(int x = 1;x <= min(2*M,n-idx); x++){
            stones += piles[idx+x-1];
            
            if(person == 1){
                result = max(result,stones+solve(idx+x,0,max(M,x),piles,n,dp));
            }
            else{
                result = min(result,solve(idx+x,1,max(M,x),piles,n,dp));
            }
        }
        
        return dp[idx][person][M] = result;
    }
    
    
    
    
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size()+1,vector<vector<int>> (2,vector<int>(piles.size()+1,-1)));
        return solve(0,1,1,piles,piles.size(),dp);
    }
};