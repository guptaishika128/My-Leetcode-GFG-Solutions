class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0;
        int j = 0;
        string s = "";
        bool flag = true;
        while(i<word1.length() && j<word2.length()){
            if(flag){
                s += word1[i++];
            }
            else{
                s += word2[j++];
            }
              flag = !flag;
        }
        while(i<word1.length()){
            s += word1[i++];
        }
        while(j<word2.length()){
            s += word2[j++];
        }
        
        return s;
    }
};