class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
       if(nums.size()<=2){
           return result;
       }
        
        sort(nums.begin() , nums.end());
        
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 && nums[i] != nums[i-1])){
                int lo = i+1;
                int hi = nums.size()-1;
                int sum = 0-nums[i];
                
                while(lo<hi){
                    if(nums[lo] + nums[hi] == sum){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[lo]);
                        t.push_back(nums[hi]);
                        result.push_back(t);
                    
                    while(lo<hi && nums[lo] == nums[lo+1]){
                        lo++;
                    }
                    while(lo<hi && nums[hi] == nums[hi-1]){
                        hi--;
                    } 
                        lo++;
                        hi--;
                    }
                    else if(nums[lo] + nums[hi] > sum){
                        hi--;
                    } else{
                        lo++;
                    }
                    
                }
                
            }
        }
        return result;
    }
}; 