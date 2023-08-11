class Solution {
public:
    bool isPalindrome(string s) {
        if(s == ""){
            return true;
        }
        string temp  = "";
        for(int i=0;i<s.length();i++){
            if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
                temp += tolower(s[i]);
            }
            if((s[i]>='0' && s[i]<='9')){
                temp += s[i];
            }
        }
        
        int st = 0;
        int e = temp.length()-1;
        
        while(st<e){
            if(temp[st] != temp[e]){
                return false;
            }
            st++;
            e--;
        }
        return true;
    }
};