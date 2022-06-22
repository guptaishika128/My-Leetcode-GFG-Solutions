class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0 ;
        int right = 0;
        int maxi = 0;
        set<int> st;
        while(right<s.length()){
            if(st.find(s[right])==st.end()){
                st.insert(s[right]);
                right++;
                maxi = (maxi>st.size())?maxi:st.size();
            } else{
                st.erase(s[left]);
                left++;
            }
        }
        return maxi;
    }
};