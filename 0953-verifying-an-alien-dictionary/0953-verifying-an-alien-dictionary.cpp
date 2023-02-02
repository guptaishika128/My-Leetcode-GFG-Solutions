class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        // Mapping problem
        
        unordered_map<char,int> mp;
        
        for(int i=0;i<order.length();i++){
            mp[order[i]] = i;
        }
        
        for(int i=1;i<words.size();i++){
            string one = words[i-1];
            string two = words[i];
            
            for(int j=0;j<one.length();j++){
                if(j==two.length()){
                    return false;
                }
                
                char o = one[j];
                char t = two[j];
                
                if(mp[o]>mp[t]){
                    return false;
                } else if(mp[o]<mp[t]){
                    break;
                }
            }
        }
        return true;
    }
};