class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> mp(26,0);
        
        for(int i=0;i<magazine.length();i++){
            mp[magazine[i]-'a']++;
        }
        for(int i=0;i<ransomNote.length();i++){
            if (--mp[ransomNote[i] - 'a'] < 0)
                return false;
        }
        return true;
    }
};