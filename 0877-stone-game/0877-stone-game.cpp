class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = accumulate(piles.begin(),piles.end(),0);
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;j++,i++){
                if(g == 0){
                    dp[i][j] = piles[i];
                } else if(g == 1){
                    dp[i][j] = max(piles[i],piles[j]);
                } else{
                    int case1 = piles[i] + min(dp[i+1][j-1],dp[i+2][j]);
                    int case2 = piles[j] + min(dp[i][j-2],dp[i+1][j-1]);
                    dp[i][j] = max(case1,case2);
                }
            }
        }
        
        return dp[0][n-1] > sum/2;
    }
};