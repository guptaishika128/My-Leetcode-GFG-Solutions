class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int m = words[0].size();
        vector<int> ans;
        int k = n*m;
        if(s.length()<k){
            return ans;
        }

        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[words[i]]++; 
        }
        for(int i=0;i<=s.length()-k;i++){
            unordered_map<string,int> temp;
            int j=0;
            while(j<n){ 
                string p = s.substr(i+j*m,m);
                temp[p]++;
                if(temp[p]>mp[p]){
                    break;
                }
                j++;
            }
            temp.clear();
            if(j == n){
                ans.push_back(i);
            }
        }
        return ans;
    }
};