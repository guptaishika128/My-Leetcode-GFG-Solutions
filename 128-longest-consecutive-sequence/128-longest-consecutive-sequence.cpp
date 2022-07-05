class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        
        int longestStreak = 0;
        
        for(int num:s){
            if(s.find(num-1)==s.end()){
                int current = num;
                int currentStreak = 1;
                
                while(s.find(current+1)!=s.end()){
                    current += 1;
                    currentStreak += 1;
                }
             
            longestStreak = max(longestStreak,currentStreak);
        }
    }
        return longestStreak;
    }
};