class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
       int n = nums.size();
        int ans =INT_MIN;
        
        for(int i=0;i<n;i++){
            int neg = 0, pos = 0, first_neg = -1 , last_neg = -1;
            int j;
            for(j=i;j<n;j++){
                if(nums[j]<0){
                    neg++;
                }
                if(nums[j]>0){
                    pos++;
                }
                if(nums[j]<0 && first_neg==-1){
                    first_neg = j;
                }
                if(nums[j]<0){
                    last_neg = j;
                }
                if(nums[j] == 0){
                    break;
                }
            }
            
            if(neg%2==0){
                ans = max(ans,neg+pos);
            }
            
            if(neg%2==1){
                ans = max(ans , j-first_neg-1);
                ans = max(ans,last_neg-i);
            }
            i=j; // new subaray
        }
        return ans;
    }
};