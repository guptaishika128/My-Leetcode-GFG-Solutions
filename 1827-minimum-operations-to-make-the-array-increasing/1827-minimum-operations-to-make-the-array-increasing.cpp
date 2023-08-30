class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        if(n == 2){
            if(nums[0]<nums[1]){
                return 0;
            }
            else {
                return nums[0]-nums[1] + 1;
            }
        }
        
        priority_queue<int> pq;
        int sum  = 0;
        pq.push(nums[0]);
        for(int i=1;i<n;i++){
            if(pq.top()>=nums[i]){
                int a = pq.top();
                sum += pq.top()-nums[i]+1;
                pq.push(a+1);
            }else{
            pq.push(nums[i]);
            }
        }
        return sum;
    }
};