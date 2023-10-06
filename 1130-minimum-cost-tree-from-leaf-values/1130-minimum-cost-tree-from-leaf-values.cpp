class Solution {
public:
    int maxi[41][41];
    int dp[41][41];
    
    int solve(int left, int right){
        if(left == right){
            return 0; // leaf node
        }
        
        if(dp[left][right]!=-1){
            return dp[left][right];
        }
        
        int ans = 1<<30;
        
        for(int k=left;k<right;k++){
            ans = min(ans, (maxi[left][k] * maxi[k+1][right]) + solve(left,k) + solve(k+1,right));
        }
        
        return dp[left][right] = ans;
    }
    
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            maxi[i][i] = arr[i];
            for(int j=i+1;j<n;j++){
                maxi[i][j] = max(maxi[i][j-1],arr[j]);
            }
        }
        
        return solve(0,n-1);
    }
};