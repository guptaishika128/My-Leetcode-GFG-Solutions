class Solution {
public:
    bool checkStrings(string s1, string s2) {
   
        int n= s1.length();
        vector<int> odd(26,0);
        vector<int> even(26,0);
        
        for(int i=0;i<n;i++){
            if(i%2 != 0){
                odd[s1[i]-'a']++;
                odd[s2[i]-'a']--;
            }
            else{
                 even[s1[i]-'a']++;
                 even[s2[i]-'a']--;
            }
        }
        
        for(int i=0;i<odd.size();i++){
            if(even[i]!=0 || odd[i]!=0){
                return false;
            }
        }
        return true;
    }
};