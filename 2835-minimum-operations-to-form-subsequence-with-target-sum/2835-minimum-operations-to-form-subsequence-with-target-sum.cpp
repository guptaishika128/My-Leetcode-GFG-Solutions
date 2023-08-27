class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        int n = nums.size();
        
       long long total = accumulate(nums.begin(),nums.end(),0L);
        if(total < target){
            return -1;
        }
        int ans  = 0;
        priority_queue<int> pq;
        
        for(auto it:nums){
            pq.push(it);
        }
        
        while(target>0){
            int front= pq.top();
            total -= front;
            pq.pop();
            
            if(target>=front){
                target -= front;
            }
            else if(target<front && total<target){
                ans++;
                total += front;
                pq.push(front/2);
                pq.push(front/2);
            }
            
            
            if(pq.empty() && target!=0){
                return -1;
            }
        }
        
        return ans;
    }
};