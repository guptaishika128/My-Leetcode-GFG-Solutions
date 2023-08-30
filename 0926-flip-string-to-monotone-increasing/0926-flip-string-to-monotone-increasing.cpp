class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<int> ones(n); // To store number of 1s on the left side
        vector<int> zeroes(n); // To store number of 0s on the right side
        
        if(s[0] == '1'){
                ones[0] = 1;
            } else{
                ones[0] = 0;
            }
        
        for(int i=1;i<n;i++){
            if(s[i] == '1'){
                ones[i] = ones[i-1] + 1;
            } else{
                ones[i] = ones[i-1];
            }
        }
        
        if(s[n-1] == '0'){
                zeroes[n-1] = 1;
            } else{
                zeroes[n-1] = 0;
            }
            
        for(int i=n-2;i>=0;i--){
            if(s[i] == '0'){
                zeroes[i] = zeroes[i+1] + 1;
            } else{
                zeroes[i] = zeroes[i+1];
            }
        }
        
        int mini_flips = INT_MAX;
        
        for(int i=0;i<n;i++){
            int curr_flips = (i == 0) ? 0 :ones[i-1];
            curr_flips += (i == n-1) ? 0 : zeroes[i];
            
            mini_flips = min(mini_flips , curr_flips);
        }
        
        return mini_flips;
    }
};