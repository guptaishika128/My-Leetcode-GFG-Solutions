class Solution {
// private:
//     bool canMakeValidSubstring(string s, int substringlen , int k){
//         // takes a window of length substring_len on the given string and see if its valid
//         vector<int> freq(26,0);
//         int maxfreq = 0;
//         int start = 0;
        
//         for(int end = 0;end<s.length();end++){
//             freq[s[end]-'A']++;
            
//             if(end-start+1>substringlen){
//                 freq[s[start]-'A']--;
//                 start++;
//             }
            
//             maxfreq = max(maxfreq , freq[s[end]-'A']);
            
//             if(substringlen - maxfreq <= k){
//                 return true;
//             }
//         }
        
//         return false;
//     }
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int max_freq = 0;
        int start = 0;
        int result = 0;
        for(int end = 0;end<s.length();end++){
            freq[s[end]-'A']++;
            
            max_freq = max(max_freq,freq[s[end]-'A']);
            
            if(end-start+1-max_freq>k){
                freq[s[start]-'A']--;
                start++;
            }
            result = max(result,end-start+1);
        }
        return result;
    }
};