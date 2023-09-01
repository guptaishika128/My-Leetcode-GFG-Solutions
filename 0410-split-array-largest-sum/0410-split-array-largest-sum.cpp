class Solution {
public:
    int count(vector<int>& nums, int mid){
        int split = 1;
        long long curr = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]+curr <= mid){
                curr += nums[i];
            }
            else{
                curr = nums[i];
                split++;
            }
        }
        return split;
    }
    
    
    
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
    
        if(n == k){
            return *max_element(nums.begin(),nums.end());
        }
        int total = accumulate(nums.begin(),nums.end(),0);
         if(k == 1){
            return total;
        }
        
        int low = *max_element(nums.begin(),nums.end());;
        int high = total;
        int ans = 0;
        while(low<=high){
            int mid = (low+high)/2;
            int noOfSplits = count(nums,mid);
            if(noOfSplits > k){
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