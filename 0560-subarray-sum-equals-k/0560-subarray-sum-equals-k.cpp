class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      int n = nums.size();
      vector<int> prefix(n);
        prefix[0] = nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i] = nums[i] + prefix[i-1];
        }
        unordered_map<int,int> mp;
        int a = 0;
        for(int i=0;i<n;i++){
            if(prefix[i] == k){
                a++;
            }
            if(mp.find(prefix[i] - k) != mp.end()){
                a += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
        }
        return a;
    
    }
};