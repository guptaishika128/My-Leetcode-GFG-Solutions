class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> shash(26,0);
        vector<int> phash(26,0);
        int len = s.length();
        int window = p.length();
        
        int left = 0 , right = 0;
        
        if(len<window){
            return ans;
        }
        
        while(right<window){
            shash[s[right]-'a'] += 1;
            phash[p[right]-'a'] += 1;
            right++;
        }
        right -= 1;
        
        while(right<len){
            if(phash == shash){
                ans.push_back(left);
            }
            right += 1;
            if(right != len){
                shash[s[right]-'a'] += 1;
            }
            shash[s[left]-'a'] -= 1;
            left++;
        }
        
        return ans;
    }
};