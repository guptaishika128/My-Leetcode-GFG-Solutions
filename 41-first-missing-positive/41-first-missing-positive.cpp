class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     unordered_map<int,int> mp;
     mp[0]= true;
        int n = nums.size();
     for(int i=0;i<n;i++){
         mp[nums[i]] = true;
     }
     for(int i=1;i<=n+1;i++){
         if(mp[i]==false){
             return i;
         }
     }
     return -1;
    }
};