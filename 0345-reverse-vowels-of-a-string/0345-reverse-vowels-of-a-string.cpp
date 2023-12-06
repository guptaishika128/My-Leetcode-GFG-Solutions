class Solution {
public:
    string reverseVowels(string s) {
//         vector<char> v;
        
//         for(int i=0;i<s.length();i++){
//             if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
//                 v.push_back(s[i]);
//             }
//         }
        
//         reverse(v.begin(),v.end());
        
//         int k = 0;
//         for(int i=0;i<s.length();i++){
//              if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'|| s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
//                  s[i] = v[k++];
//             }
//         }
//         return s;
        unordered_set<char> vowel = {'a','e','i','o','u','A','E','I','O','U'};
        
        int n = s.length();
        
        int i=0, j=n-1;
        while(i<j){
            while(i<j && vowel.find(s[i])==vowel.end()){
                i++;
            }
            while(i<j && vowel.find(s[j])==vowel.end()){
                j--;
            }
            if(i<j){
                swap(s[i],s[j]);
            }
            i++;
            j--;
        }
        return s;
        
        
    }
};