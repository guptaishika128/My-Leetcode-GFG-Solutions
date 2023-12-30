class Solution {
public:
    bool makeEqual(vector<string>& words) {
        if(words.size() == 1){
            return true;
        }
        
        vector<int> cnt(26,0);
        for(int i=0;i<words.size();i++){
            for(int j=0;j<words[i].size();j++){
                cnt[words[i][j]-'a']++;
            }
        }
        
        for(int i=0;i<26;i++){
            if(cnt[i] != 0){
                if(cnt[i]%words.size() !=0){
                    return false;
                }
            }
        }
        return true;
        
    }
};