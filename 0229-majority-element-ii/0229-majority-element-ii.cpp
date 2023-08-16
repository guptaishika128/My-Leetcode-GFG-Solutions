class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       vector<int> res; // for storing result
//        unordered_map<int,int> mp; // map for storing frequency of vector elemnts
        
//         for(int i=0;i<nums.size();i++){
//             mp[nums[i]]++;
//         }
        
//         for(auto it:mp){
//             if(it.second>nums.size()/3){
//                 res.push_back(it.first);
//             }
//         }
//         return res;
       
   
         
        int num1 = -1, num2 = -1, count1 = 0 ,count2 = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1){
                count1++;
            } else if(nums[i]==num2){
                count2++;
            } else if(count1==0){
                num1 = nums[i];
                count1 = 1;
            } else if(count2==0){
                num2 = nums[i];
                count2=1;
            } else{
                count1--;
                count2--;
            }
        }
        int cnt1 = 0 , cnt2 =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == num1){
                cnt1++;
            }
            else if(nums[i] == num2){
                cnt2++;
            }
        }
        
        if(cnt1>nums.size()/3){
            res.push_back(num1);
        }
        if(cnt2>nums.size()/3){
            res.push_back(num2);
        }
        return res;
    }
};