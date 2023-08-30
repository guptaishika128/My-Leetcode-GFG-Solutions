class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long res = 0;
        for(int i=1;i<s.length();i++){
            if(s[i] != s[i-1]){
                res += min(i,n-i);
            }
        }
        return res;
    }
};