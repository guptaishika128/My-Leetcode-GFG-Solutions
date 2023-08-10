class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = 0;
        string temp = "";
        string prev = "";
        for(int i=0;i<s.length();i++){
            if(s[i] == ' '){
                temp = ""; 
            }else if(s[i]!=' '){
                temp += s[i];
                prev = temp;
            }
        }
        return prev.length();
    }
};