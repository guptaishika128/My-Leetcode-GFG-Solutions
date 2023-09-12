class Solution {
public:
    int minDeletions(string s) {
        int n = s.length();
        vector<int> count(26,0);
        for(int i=0;i<n;i++){
            count[s[i]-'a']++;
        }
        
        int cnt = 0;
        
        sort(count.begin(),count.end());
        
        for(int i=24;i>=0;i--){
            if(count[i] == 0){
                break;
            }
            
            if(count[i]>=count[i+1]){
                int prev = count[i];
                count[i] = max(0,count[i+1]-1);
                cnt += (prev-count[i]);
            }
        }
        return cnt;
    }
};