class Solution {
public:
    const int MOD = 1e9 + 7;
      int dp[301][301];
    
    int solve(int remainingSum, int power, int base){
      //calculate power
        int result = pow(base, power);

        if(dp[remainingSum][base]!=-1){
            return dp[remainingSum][base];
        }
        if(remainingSum == result)
            return 1;
        if(remainingSum < result)
            return 0;
          //Two recursive calls one to include current base's power in sum another to exclude
        int x = solve(remainingSum - result, power, base + 1);
        int y = solve(remainingSum, power, base+1);
        return dp[remainingSum][base] = (x + y)%MOD;
    }
    
    
    int numberOfWays(int n, int x) {
        memset(dp,-1,sizeof(dp));
        return solve(n,x,1);
    }
};