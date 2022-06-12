class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
         int i,maxx;
        if(nums.size()==1) return nums[0]; //base case
        maxx = *max_element(nums.begin(),nums.end());//maximum of nums array         
        vector<int> sameelemsum(maxx+1,0); //same element sum array
        for(i=0;i<nums.size();i++) sameelemsum[nums[i]]+=nums[i];	
        
        //constant space house robber solution base cases
        int prev2=sameelemsum[0];
        int prev=max(sameelemsum[0],sameelemsum[1]);
        int curr;
        //House robber on same element sum array
        for(i=2;i<sameelemsum.size();i++){
            curr=max(prev,prev2+sameelemsum[i]);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};