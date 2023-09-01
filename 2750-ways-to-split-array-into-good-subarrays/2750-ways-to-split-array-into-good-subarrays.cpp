class Solution {
public:
    const int MOD = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n= nums.size();
        int countOne = 0;
        vector<int> ones;
        for(int i= 0;i<n;i++){
            if(nums[i] == 1){
                ones.push_back(i);
                countOne++;
            }
        }
        
        if(countOne == 1){
            return 1;
        } else if(countOne == 0){
            return 0;
        }
        
        long long int ans = 1;
        
        for(int i=1;i<ones.size();i++){
            ans = ans*(ones[i]-ones[i-1])%MOD;
        }
        return ans%MOD;
    }
};