class Solution {
public:
    bool isValid(string s) {
if(s.size()<=1) return false;
stack<char> stk;
for(int i=0;i<s.size();i++){
if(s[i]==')' and !stk.empty() and stk.top()=='(' ) stk.pop();
else if(s[i]=='}' and !stk.empty() and stk.top()=='{') stk.pop();
else if(s[i]==']' and !stk.empty() and stk.top()=='[' ) stk.pop();
else stk.push(s[i]);
}
return stk.empty();
    }
};