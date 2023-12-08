class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        vector<int> nums(arr.begin(),arr.end());
        int n = arr.size();
         int l = 1 , r = n-2;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid;
            }
            else if(nums[mid-1]>nums[mid]){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return -1;
    }
};