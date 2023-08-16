class Solution {
public:
    int maxSumarray(vector<int>& nums, int l , int r){
        if(l>r){
            return INT_MIN;
        }
        int mid = (l+(r-l)/2);
        
        int left_Sum = 0;
        int right_Sum = 0;
        
        for(int i=mid-1, currsum = 0;i>=l;i--){
            currsum +=nums[i];
            left_Sum = max(currsum,left_Sum);
        }
        
        for(int i=mid+1,currsum = 0;i<=r;i++){
            currsum += nums[i];
            right_Sum = max(right_Sum , currsum);
        }
        
        return max(maxSumarray(nums,l,mid-1) ,max(maxSumarray(nums,mid+1,r),left_Sum + nums[mid] + right_Sum));
        
    }
    int maxSubArray(vector<int>& nums) {
         int ans=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(ans<sum)
                ans=sum;
            if(sum<0)
                sum=0;
        }
        return ans;
       
    //     int ans = maxSumarray(nums,0,nums.size()-1);
    // return ans;
    }
};