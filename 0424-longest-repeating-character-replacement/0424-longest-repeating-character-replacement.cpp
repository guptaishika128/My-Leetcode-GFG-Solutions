class Solution {
private:
    bool canMakeValidSubstring(string s, int substringlen , int k){
        // takes a window of length substring_len on the given string and see if its valid
        vector<int> freq(26,0);
        int maxfreq = 0;
        int start = 0;
        
        for(int end = 0;end<s.length();end++){
            freq[s[end]-'A']++;
            
            if(end-start+1>substringlen){
                freq[s[start]-'A']--;
                start++;
            }
            
            maxfreq = max(maxfreq , freq[s[end]-'A']);
            
            if(substringlen - maxfreq <= k){
                return true;
            }
        }
        
        return false;
    }
public:
    int characterReplacement(string s, int k) {
        int lo = 1;
        int hi = s.length()+1;
        
        while(lo+1<hi){
            int mid = (lo+hi)/2;
            
            if(canMakeValidSubstring(s,mid,k)){
                lo = mid;
            } else{
                hi = mid;  
            }
        }
        return lo;
    }
};