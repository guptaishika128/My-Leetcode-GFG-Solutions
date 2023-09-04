class Solution {
public:
  
    vector<string> removeAnagrams(vector<string>& words) {
        
        vector<string> ans;
        int n = words.size();
        
        vector<int> v1(26,0);
        
        ans.emplace_back(words[0]);
        for(auto it:words[0]){
            v1[it-'a']++;
        }
        
        for(int i=1;i<n;i++){
            vector<int> v2(26,0);
            
            for(auto it:words[i]){
                v2[it-'a']++;
            }
            if(v1 == v2){
                continue;
            }
            else{
               ans.emplace_back(words[i]);
                v1 = v2;
            }
        }
        return ans;
    }
};