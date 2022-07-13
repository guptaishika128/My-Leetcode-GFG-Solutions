class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
      int start = 0;
        int end = n - 1;

        // If the first element is less than the last element then there is no rotation. The first element is minimum.
        if(nums[start] <= nums[end]) {
            return nums[start];
        }

        while(start <= end) {
            int mid = (start + end) / 2;

            // If the middle element is smaller than its previous element, then it is the minimum element
            if(mid > 0 && nums[mid] < nums[mid-1]) {
                return nums[mid];
            }

            // If the middle is greater than its next element, then the next element is the minimum element
            if(mid < n-1 && nums[mid] > nums[mid+1]) { 
                return nums[mid+1];
            }

            if(nums[start] <= nums[mid]) { // left array is sorted. So the pivot is on the right side
                start = mid+1;
            } else { //right array is sorted. So the pivot is on the left side
                end = mid-1;
            }
        }

        return -1;
    }
};