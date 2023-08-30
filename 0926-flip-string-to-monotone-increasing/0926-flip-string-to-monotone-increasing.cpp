class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        int count1 = 0;
        int flips = 0;
        
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                count1++;
            }
            else{
                flips++;
                flips = min(flips,count1);
            }
        }
        return flips;
    }
};