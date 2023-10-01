class Solution {
public:
    int maxSubarrays(vector<int>& nums) {
        int maxi = INT_MAX;
        
        for(auto it:nums){
            maxi = maxi&it;
        }
        
        if(maxi != 0){
            return 1;
        }
        int b = INT_MAX;
        int cnt = 0;
        for(auto it:nums){
            b = b&it;
            if(b == 0){
                cnt++;
                b = INT_MAX;
            }
        }
        return cnt;
    }
};