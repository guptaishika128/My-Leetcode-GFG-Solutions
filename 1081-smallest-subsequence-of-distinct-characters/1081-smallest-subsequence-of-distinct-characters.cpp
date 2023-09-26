class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.length();
        vector<int> lastIndex(26,0);
        stack<int> st;
        
        vector<bool> visited(26,false);
        
        for(int i=0;i<n;i++){
            lastIndex[s[i]-'a'] = i;
        }
        
        for(int i=0;i<n;i++){
            int curr = s[i]-'a';
            if(visited[curr]){
                continue;
            }
            
            while(st.size()>0 && st.top()>s[i] && i<lastIndex[st.top()-'a']){
                visited[st.top()-'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            visited[curr] = true;
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