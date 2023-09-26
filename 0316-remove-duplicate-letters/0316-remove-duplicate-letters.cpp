class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastIndex(26,0);
        stack<char> st;
        vector<bool> seen(26,false);
        
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a'] = i; // keep track of the last index of character
        }
        
        for(int i=0;i<n;i++){
            int curr = s[i]-'a';
            if(seen[curr]){
                continue;
            }
            
            while(st.size()>0 && st.top()>s[i] && i<lastIndex[st.top()-'a']){
                seen[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            seen[curr] = true;
        }
        string ans = "";
        
        while(st.size()>0){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};