class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
//         sort(nums.begin(),nums.end()); // Distorting the array 
        
        if(nums.size()<=1){
            return nums.size();
        }
        
//         int currentStreak = 1;
//         int maxi = 0;
        
//         for(int i=1;i<nums.size();i++){
//             if(nums[i] != nums[i-1]){
//                 if(nums[i] == (nums[i-1] + 1)){
//                     currentStreak++; 
//                 } 
//                 else{
//                      maxi = max(maxi , currentStreak);
//                     currentStreak = 1;
//                 }
//             } 
//         }
//         return max(maxi,currentStreak);
        
        int maxi = 1;
        unordered_set<int> s;
        
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        
        for(auto it:s){
            if(s.find(it-1) == s.end()){
                int curr =1;
                int x = it;
                while(s.find(x+1) != s.end()){
                    curr++;
                    x =x+1;
                }
                maxi = max(maxi,curr);
            }
        }
        return maxi;
    }
};