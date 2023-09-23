class Solution {
public:
    unordered_set<string> st;    int ans = 0;
       
    void dfs(int idx, string &s){
     
        
        if(st.size()>ans){
            ans = st.size();
        }
        if(idx >= s.length()){
            return;
        }
        string temp = "";
        for(int i=idx;i<s.length();i++){
            temp += s[i];
            if(st.find(temp)==st.end()){
                st.insert(temp);
                dfs(i+1,s);
                st.erase(temp);
            }
        }
        
    }
    
    
    
    int maxUniqueSplit(string s) {
        dfs(0,s);
        return ans;
    }
};