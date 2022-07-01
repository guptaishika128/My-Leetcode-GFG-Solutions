class Solution {
public:
    string removeBackspace(string &str){
        int n = str.length();
        
        int idx = 0;
        
        for(int i=0;i<n;i++){
            if(str[i] != '#'){
                str[idx] = str[i];
                idx++;
            } else if(str[i]=='#' && idx>=0){
                idx--;
            }
            if(idx<0){
                idx = 0;
            }
        }
        
        return str.substr(0,idx);
    }
    bool backspaceCompare(string s, string t) {
        if(removeBackspace(s) == removeBackspace(t)){
            return true;
        }
        return false;
    }
};