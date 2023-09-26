class Solution {
public:
    bool checkRecord(string s) {
        int maxi = 'P'-'A';
        bool flag = false;
        vector<int> cnt(maxi+1,0);
        int cnt1 = 0;
        int max_freq = 0;
        for(int i=0;i<s.length();i++){
            cnt[s[i]-'A']++;
            if(s[i]=='L'){
                cnt1++;
                max_freq = max(max_freq,cnt1);
            }
            else{
                cnt1 = 0;
            }
        }
        if(cnt[0]<2 && max_freq<3){
            flag = true;
        }
        else{
            flag = false;
        }
        return flag;
    }
};