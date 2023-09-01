class Solution {
public:
    int check(vector<int>& nums , int mid){
        int total = 0;
        int j = 0;
       int n = nums.size();
        
        for(int i=0;i<n;i++){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
                }
                j--;
                total += (j-i);
            }
        return total;
    }
    
    
    
    
    
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int low = 0;
        int high = nums[n-1] - nums[0];
        int ans = 0;
        while(low<=high){
            int mid =(low+high)/2;
            
            int sum = check(nums,mid);
            if(sum < k){
                low = mid+1;
            }
            else{
                ans = mid;
                high = mid-1;
            }
        }
        return ans;
    }
};