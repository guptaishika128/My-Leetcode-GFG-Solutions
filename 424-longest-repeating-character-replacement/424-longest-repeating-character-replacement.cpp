class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26,0);
        int start = 0 ;
        int n = s.length();
        int maxCharCount = 0;
        int result = 0;
        
        for(int end=0;end<n;end++){
            count[s[end]-'A'] += 1;
            if(maxCharCount < count[s[end]-'A']){
                maxCharCount = count[s[end]-'A'];
            }
            while((end-start+1-maxCharCount)>k){
                count[s[start]-'A']--;
                start++;
                for(int i=0;i<26;i++){
                    if(maxCharCount<count[i]){
                        maxCharCount = count[i];
                    }
                }
            }
            result = max(result,end-start+1);
        }
        return result;
    }
};