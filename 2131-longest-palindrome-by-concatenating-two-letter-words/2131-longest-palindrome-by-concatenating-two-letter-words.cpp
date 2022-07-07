class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> mp;
        int unpaired =0;
        int ans = 0;
        
        for(auto x: words){
            if(x[0]==x[1]){
                if(mp[x]>0){
                    unpaired--;
                    mp[x]--;
                    ans+=4;
                }
                else{
                    unpaired++;
                    mp[x]++;
                }
            } else{
                string rev = x;
                reverse(x.begin(),x.end());
                if(mp[rev]>0){
                    ans+=4;
                    mp[rev]--;
                } else{
                    mp[x]++;
                }
            }
        }
        if(unpaired>0){
            ans+=2;
        }
        return ans;
    }
};