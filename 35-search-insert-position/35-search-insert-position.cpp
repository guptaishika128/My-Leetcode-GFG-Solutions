class Solution {
public:
    int binarySearch(vector<int> &nums, int l, int r, int target)
{  int mid = l + (r - l) / 2;
    if (r >= l) {
        
       
        if (nums[mid] == target)
            return mid;
  
        if (nums[mid] > target)
            return binarySearch(nums, l, mid - 1, target);

        return binarySearch(nums, mid + 1, r, target);
    }
   
   return mid;
}
 
    int searchInsert(vector<int>& nums, int target) {
        return binarySearch(nums,0,nums.size()-1,target);
        
    }
};