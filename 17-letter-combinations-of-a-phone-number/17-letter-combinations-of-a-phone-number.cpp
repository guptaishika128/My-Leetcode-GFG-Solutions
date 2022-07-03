class Solution {
public:
    vector<string> dict = {"", "", "abc" , "def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
  
    vector<string> letter(string digits){
        if(digits.size()==0){  //base case
            vector<string> hhh;
            hhh.push_back("");
            return hhh;
        }
        
        char ch = digits[0];   //taking first element
        string s = digits.substr(1);  //all elements except first one
        vector<string> str = letter(s);   //we will have faith in our function that it will definitely return the answer of all substrings except the first subtring
        
        vector<string> ans;
        
        string st = dict[ch-48]; //ascii value of 0->48, 1->49, 2->50 (we can also write ch-'0')
        for(int i=0;i<st.size();i++){  //now we will just add the rest answer with the first element
            char ch = st[i];
            for(string bh:str){
                ans.push_back(ch+bh);
            }
        }
        
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> aaaaa;
        if(digits.size()==0)return aaaaa; //digits = ""; 
        
        return letter(digits);
    }
};