class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> answer(n);
        int count = 0;
        int mul = 1;
        int idx = -1;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count++;
                idx = i;
            }
            else{
                mul *= nums[i];
            }
        }
        
        if(count == 0){
            for(int i=0;i<n;i++){
                answer[i] = mul/nums[i];
            }
        }
        else if(count  == 1){
            answer[idx] = mul;
        }
        return answer;
//         output[0] = 1;

//         for(int i=1;i<n;i++){
//             output[i] = nums[i-1]*output[i-1];
//         }
        
//         int R=1;
//         for(int i=n-1;i>=0;i--){
//             output[i] = output[i]*R;
//             R = R*nums[i];
//         }
//     return output;
    }
};