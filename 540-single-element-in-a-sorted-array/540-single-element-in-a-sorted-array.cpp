class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    /*   TC - O(N)  
        int xorr = 0;
        for(int i=0;i<nums.size();i++){
            xorr ^= nums[i];
        }
        return xorr;
        */
        // FOR TC - O(logN) -> BINARY SEARCH IS USED
        int low = 0;
        int high = nums.size()-2;
        
        while(low<=high){
            int mid = (low+high)/2;
            
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            } else{
                if(nums[mid]==nums[mid+1]){
                    high = mid-1;
                } else{
                    low = mid+1;
                }
            }
        }
        return nums[low];
    }
};