class Solution {
public:
    bool isPalindrome(string &s, int lo, int hi){
        while(lo<hi){
            if(s[lo++]!=s[hi--]){
                return false;
            }   
        }
        return true;
    }
  
    int solve(int idx,string s,vector<int>& dp){
        int n = s.length();
        if(idx == n){
            return 0;
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int minCut = INT_MAX;
        
        for(int j=idx;j<n;j++){
            if(isPalindrome(s,idx,j)){
                int cut = 1 + solve(j+1,s,dp);
                minCut = min(minCut,cut);
            }
        }
        return dp[idx] = minCut;
    }
    
    int minCut(string s) {
        int n= s.length();
        vector<int> dp(n+1,0);
        dp[n] = 0;
        
        for(int i=n-1;i>=0;i--){
             int minCut = INT_MAX;
        
            for(int j=i;j<n;j++){
                if(isPalindrome(s,i,j)){
                    int cut = 1 + dp[j+1];
                    minCut = min(minCut,cut);
                }
            }
            dp[i] = minCut;
        }
       return dp[0]-1;
        
    }
};