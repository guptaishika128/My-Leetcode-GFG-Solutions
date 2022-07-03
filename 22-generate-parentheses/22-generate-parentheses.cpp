class Solution {
public:
    void generate(int n, int ob , int cb , string res , vector<string>& ans){
        if(ob == n && cb == n){
            ans.push_back(res);
        }
        else{
            if(ob<n){
                generate(n,ob+1,cb,res+'(',ans);
            }
            if(cb<ob){
                generate(n,ob,cb+1,res+')',ans);
            }
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string res;
        generate(n,0,0,res,ans);
        return ans;
    }
};