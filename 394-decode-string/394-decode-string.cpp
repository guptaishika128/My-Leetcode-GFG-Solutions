class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        
        for(int i=0;i<s.length();i++){
            if(s[i]!=']'){
                st.push(s[i]);
            } else{
                string temp;
                
                while(!st.empty() && st.top()!='['){
                    temp = st.top() + temp;
                    st.pop();
                }
                
                st.pop(); // Pop opening bracket too
                
                string count;
                
                while(!st.empty() && isdigit(st.top())){
                    count = st.top() + count;
                    st.pop();
                }
                
                int number = stoi(count); // converting string to integer
                string repeat;
                
                for(int j=0;j<number;j++){
                    repeat+= temp;
                }
                for(char c:repeat){
                    st.push(c);
                }
            }
        }
        
        string res;
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        
        return res;
    }
};