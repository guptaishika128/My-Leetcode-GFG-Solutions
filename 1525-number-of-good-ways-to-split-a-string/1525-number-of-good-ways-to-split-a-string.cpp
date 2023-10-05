class Solution {
public:
    int numSplits(string s) {
        int n = s.length();
        vector<int> prefix(n), suffix(n);
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            prefix[i] = st.size();
        }
        
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            suffix[i] = st.size();
        }
        
        int ans = 0;
        for(int i=1; i<n; i++) {
              if(prefix[i-1] == suffix[i]) {
                    ans++;
              }   
        }
        return ans;
    }
};