class Solution {
public:
     int dp[501][501];
      int solve(int l, int r, vector<int>&a,int x)
    {
        if(l>=r) return 0;
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans= min({ min(x, a[l+1]-a[l])+solve(l+2, r,a,x),  min(x, a[r]-a[l])+solve(l+1, r-1,a,x) , min(x, a[r]-a[r-1])+solve(l, r-2,a,x)});
        
        return dp[l][r]=ans;
    }
    
    int minOperations(string s1, string s2, int x) {
        int n = s1.length();
        vector<int> diff;
        
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                diff.push_back(i);
            }
        }
        if((int)diff.size()%2){
            return -1;
        }
        memset(dp,-1,sizeof(dp));
        int ans = solve(0,diff.size()-1,diff,x);
        return ans;
    }
};