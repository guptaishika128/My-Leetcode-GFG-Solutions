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
    
    void solve(string s,int idx,vector<string>& par,vector<vector<string>>& pars){
        int n = s.length();
        if(idx == n){
            pars.push_back(par);
        }
        else{
            for(int i=idx;i<n;i++){
                if(isPalindrome(s,idx,i)){
                    par.push_back(s.substr(idx,i-idx+1));
                    solve(s,i+1,par,pars);
                    par.pop_back();
                }
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
      
        vector<string> par;
        vector<vector<string>> pars;
        solve(s,0,par,pars);
        return pars;
    }
};