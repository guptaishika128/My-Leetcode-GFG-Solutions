class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()){
            return false;
        }
        
        unordered_map<char,char> map1; // to chedk mapping of s with t
        unordered_map<char,bool> map2; // to check if char of t has already been used or not
        
        
        for(int i=0;i<s.length();i++){
            char c1 = s[i];
            char c2 = t[i];
            
            if(map1.find(c1) != map1.end()){
                if(map1[c1] != c2){
                    return false;
                }
            } else{
                if(map2.find(c2) != map2.end()){
                    return false;
                } else{
                    map1[c1] = c2;
                    map2[c2] = true;
                }
            }
        }
        return true;
    }
};