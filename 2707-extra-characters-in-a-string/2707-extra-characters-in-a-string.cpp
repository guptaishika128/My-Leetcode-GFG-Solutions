class Solution {
public:
    
    int solve(int idx, string s,unordered_set<string>& st,vector<int>& dp){
        if(idx >= s.length()){
            return 0; 
        }
        if(dp[idx]!=-1){
            return dp[idx];
        }
        int value = 1 + solve(idx+1,s,st,dp);
        
        for(int i=1;idx+i<=s.length();i++){
            string temp = s.substr(idx,i);
            if(st.find(temp)!=st.end()){
                value = min(value,solve(idx+i,s,st,dp));
            }
        }
        
        return dp[idx] = value;
    }
    
    
    
    
    int minExtraChar(string s, vector<string>& dictionary) {
        int ans = 0;
        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(s.length()+1,-1);
        return solve(0,s,st,dp);
    }
};