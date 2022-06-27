class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int res = -1;
        // BS for finding first occurence
        while(low<=high){
            int mid = low + (high-low)/2;
             if(nums[mid]==target)
            {
                res=mid;
                high=mid-1;
            }
            else if(target>nums[mid]){
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        ans.push_back(res);
            
        low = 0;
        high = n-1;
        res = -1;
        
        while(low<=high){
            int mid = (low+high)/2;
             if(nums[mid]==target)
            {
                res=mid;
                low=mid+1;
            }
            else if(target>nums[mid]){
                low = mid+1;
            } else{
                high = mid-1;
            }
        }
        ans.push_back(res);
        
        return ans;
        
    }
};