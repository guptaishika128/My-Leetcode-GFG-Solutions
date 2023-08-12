class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        long long ans = 0;
        map<int,int> mp;
        int j = 0 , i=0 ;
        while(j<nums.size()){
            mp[nums[j]]++;
            sum += nums[j];
            if(j-i+1 == k){
                if (mp.size() == k) ans = max(ans,sum);
                sum -= nums[i];
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                i++;
               
            }
            j++;
        }
        return ans;
    }
};