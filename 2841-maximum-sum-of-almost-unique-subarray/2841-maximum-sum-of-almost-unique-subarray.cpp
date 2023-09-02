class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int i = 0;
        int j = 0;
        long long ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        long long sum = 0;
        
         while(j<nums.size())
        {
            sum+=nums[j];
            mp[nums[j]]++;
            while(j-i+1>k)
            {
                mp[nums[i]]--;
                sum-=nums[i];
                if(mp[nums[i]]==0)mp.erase(nums[i]);
                i++;
            }
            if(j-i+1==k)
            {
                if(mp.size()>=m)
                    ans=max(ans,sum);
            }
            j++;
        }
        return ans;
    }
};