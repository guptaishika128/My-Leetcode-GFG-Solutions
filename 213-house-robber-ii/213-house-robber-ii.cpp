class Solution {
public:
    int rob(vector<int>& nums) {
        int a1 , a2;
        if(nums.size() <= 3){
            return *max_element(nums.begin(), nums.end());
        }
        
        int inc = nums[0];
        int exc = 0;
       
        for(int i=1;i<nums.size()-1;i++){
            int ninc = exc + nums[i];
            int nexc = max(inc,exc);
            
            inc = ninc;
            exc = nexc;
        }
             a1= max(inc,exc);
        
         inc = nums[1];
         exc = 0;
       
        for(int i=2;i<nums.size();i++){
            int ninc = exc + nums[i];
            int nexc = max(inc,exc);
            
            inc = ninc;
            exc = nexc;
        }
             a2= max(inc,exc);
        
     return max(a1,a2);
    }
};