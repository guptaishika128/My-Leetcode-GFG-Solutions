class Solution {
public:
    char findTheDifference(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        vector<int> mp(26,0);
        
        for(int i=0;i<n;i++){
            mp[s[i]-'a']++;
        }
        
        for(int j=0;j<m;j++){
            mp[t[j]-'a']--;
        }
        char c;
        for(int i=0;i<26;i++){
            if(mp[i] == -1){
               c = i + 'a';
            }
        }
        return c;
    }
};