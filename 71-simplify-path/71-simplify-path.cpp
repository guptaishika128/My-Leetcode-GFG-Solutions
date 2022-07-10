class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string temp; // temp string used to store directory names / commands( . / ..)
        
        string res; // Used for resultant canonical path
        
        res.append("/"); // Every string starts from root directory
        
        for(int i=0;i<path.length();i++){
            temp.clear();
            
            while(path[i] == '/'){ // Ignore multiple consecutive slashes
                i++;
            }
            
            while(i<path.length() && path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }
            
            if(temp.compare("..") == 0){
                if(!st.empty()){
                    st.pop();
                }
            }
            else if(temp.compare(".")==0){
                continue;
            }
            else if(temp.length()!=0){
                st.push(temp);
            }
            
        }
        
        stack<string> s2;
        
        while(!st.empty()){
            s2.push(st.top());
            st.pop();
        }
        
        while(!s2.empty()){
            string temp1 = s2.top();
            if(s2.size()!=1){
                res.append(temp1 + "/");
            } else{
                res.append(temp1);
            }
            s2.pop();
        }
        return res;
    }
};