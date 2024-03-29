class Solution {
public:
    bool isPossible(string& s1 , string& s2){
        if(s1.length() != s2.length()+1){
            return false;
        }
        int first = 0;
        int second = 0;
        while(first<s1.length()){
            if(s1[first] == s2[second]){
                first++;
                second++;
            }
            else{
                first++;
            }
        }
        
        if(first == s1.length() && second == s2.length()){
            return true;
        }
        return false;
    }
    
    static bool cmp(string& s1, string& s2){
        return s1.size()<s2.size();
    }
    
    
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        
        vector<int> dp(n,1);
       
       int maxi = 1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(isPossible(words[i],words[j]) && dp[i] < dp[j] +1){
                    dp[i] = dp[j]+1;
                }
            }
            if(dp[i]>maxi){
                maxi = dp[i];
            }
        }
        return maxi;
    }
};